// Fill out your copyright notice in the Description page of Project Settings.

#include "Hunter.h"
#include "EngineUtils.h"


AHunter::AHunter() :ACreature()
{
	construction();
}
AHunter::AHunter(FVector inPos) :ACreature(inPos) {
	construction();
}


void AHunter::Tick(float DeltaTime)
{
	//as Hunter is outside the logic of creature, make a fully independent tick operation based on AActor class.
	Super::Super::Tick(DeltaTime);

	//get the velocity by checking the last and current position
	cVelocity = cPosition - cLastPosition;
	cVelocity = cVelocity / DeltaTime;
	//as it's a 2d plane, force the velocity of z axis only be 0.
	cVelocity.Z = 0.f;

	//update the position and last position parameter
	cLastPosition = cPosition;
	cPosition = GetActorLocation();

	//make some value input for neuron network decision making
	//and then change the state
	//except if it's in the hit state and not overtimed(as it needs cooltime)
	if (SetCurrentState() == STATE_HIT && !isOvertime()) {

		//prepare decision parameters
		TArray<FHitResult> hitResult = getSurroundings();
		//find pray is existed or not
		prayTarget = getPray(&hitResult);
		//find mating target is existed or not
		mateTarget = getMate(&hitResult);
		//find if the creature is dead or not
		bool isDead = (cHP <= 0);
		bool isDamaged = (cHP <= previousHP);
		//make decision
		double decision = neuroDecide(prayTarget, mateTarget, isOvertime());
		//verify decision is viable and realize it.
		double realizedDecision = realizeDecision(decision, prayTarget, mateTarget, isOvertime());
		//and adjust the neuro network after realise
		DNAController->adjustDecision(realizedDecision);

		Creature_State previousState = SetCurrentState();
		Creature_State currentState = toState(realizedDecision);


		//but if it's dead, force it to dead state machine
		//or if it's damaged and not over the time, force it to hit state machine
		if (isDamaged) {
			currentState = STATE_HIT;
		}
		if (isDead) {
			currentState = STATE_DIE;
		}

		//change the final state to the state machine if the state is different from previous one.
		if (previousState != currentState) {
			p_StateMachine->ChangeState(currentState);
		}
	}

	//update the previous HP as current HP after making decision
	previousHP = cHP;
	//if the adjusted decision is wandering, keep reset the timer, otherwise rise the timer
	if (SetCurrentState() == STATE_WANDER) {
		cTimer = 0.f;
	}
	else {
		cTimer += DeltaTime;
	}
	globalTimer += DeltaTime;

	//do the state machine tick operations
	p_StateMachine->Tick(DeltaTime);


}

//void AHunter::initialize(float inSpeed, float inSize, int inPower, int inDef, int inHP, float inSight)
//{
//	//random generate the parameters
//	cSpeed = inSpeed;
//	cSize = inSize;
//	cPower = inPower;
//	cDef = inDef;
//	cHP = inHP;
//	cSight = inSight;
//
//	//set its scaling
//	float scaleMulti = (cSize / inSize);
//	Mesh->SetRelativeScale3D(FVector(scaleMulti, scaleMulti, scaleMulti));
//
//	cPosition = GetActorLocation();
//	//set position (last position should be same in this moment)
//	cLastPosition = cPosition;
//
//	//StateMachine setup and register
//	//do it in new function as it'll be inherited by others
//	stateRegister();
//
//
//}

void AHunter::TakeDmg(int inAtk, FVector inPosition)
{
	//damage calculation: attack from others-defence
	int finalDmg = inAtk - cDef;
	//if defence is more than attack, keep it at 1 as well
	if (finalDmg <= 0) {
		finalDmg = 1;
	}
	//and then take damage to the HP
	cHP -= finalDmg;
	//and then create a impulse based on the input position
	Mesh->AddRadialImpulse(inPosition, 100.f, cPower * 100.f, ERadialImpulseFalloff::RIF_Linear, true);

}

void AHunter::overridePara(float inSpeed, float inSize, int inPower, int inDef, int inHP, float inSight)
{
	//reset the parameters into the desired value
	cSpeed = inSpeed;
	cSize = inSize;
	cPower = inPower;
	cDef = inDef;
	cHP = inHP;
	cSight = inSight;

	//set its scaling
	float scaleMulti = (cSize / inSize);
}

void AHunter::construction()
{
	//reset all array/pointer content when start up(try prevent memory leakage and crash)
	delete p_StateMachine;
	p_StateMachine = nullptr;
	delete prayTarget;
	prayTarget = nullptr;

	//Get Sphere Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Wedge_A.Shape_Wedge_A"));
	if (VisualAsset.Succeeded())
	{
		Mesh->SetStaticMesh(VisualAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/assignmentContent/Material.Material"));
	if (FoundMaterial.Succeeded())
	{
		DynamicMaterialInst = UMaterialInstanceDynamic::Create((UMaterial*)FoundMaterial.Object, Mesh);
		DynamicMaterialInst->SetVectorParameterValue(FName(TEXT("Colour")), FLinearColor(1.0, 0.0, 0.0, 1.0));
		Mesh->SetMaterial(0, DynamicMaterialInst);
	}

}

void AHunter::BeginPlay()
{
	Super::Super::BeginPlay();

	setPathfinder();
	setGenerator();
	//getting the neuron network 
	setController("Hunter");
	//initialize the parameeter
	initialize(15, 100.f, 25, 10, 15, 300.f);
	//initialize();
	cType = HUNTER;

	//set target chasing time and the kill count
	chaseTime = 10.f;
	killCount = 0;
	cSpawnCount = 2;
	//set default state
	p_StateMachine->ChangeState(STATE_WANDER);
}

ACreature * AHunter::getPray(TArray<FHitResult>* inHits)
{
	//if the hit result array has a non hunter creature, output it immediatly.
	for (auto& Hit : *inHits) {
		ACreature* pray = Cast<ACreature>((Hit.GetActor()));
		if (pray) {
			if (pray->getCreatureType() != HUNTER) {
				return pray;
			}
		}
	}
	//otherwise just return a null pointer, other function will recognize.
	return nullptr;
}

AHunter * AHunter::getMate(TArray<FHitResult>* inHits)
{
	//if the hit result array has mating hunter, output it immediatly
	for (auto& Hit : *inHits) {
		AHunter* mate = Cast<AHunter>((Hit.GetActor()));
		if (mate) {
			if (mate->isMating) {
				return mate;
			}
		}
	}
	//otherwise just return a null pointer, other function will recognize.
	return nullptr;
}

bool AHunter::isOvertime()
{
	//do it based on the state
	if (cTimer >= cTime) {
		return true;
	}
	else {
		return false;
	}
	return true;
}

void AHunter::stateRegister()
{
	p_StateMachine = new StateMachine<Creature_State, AHunter>(this, STATE_DO_NOTHING);
	//STATE_WANDER,
	p_StateMachine->RegisterState(STATE_WANDER, &AHunter::State_Wander_OnEnter, &AHunter::State_Wander_OnTick, &AHunter::State_Wander_OnExit);
	//	STATE_FLEE,
	p_StateMachine->RegisterState(STATE_FLEE, &AHunter::State_Flee_OnEnter, &AHunter::State_Flee_OnTick, &AHunter::State_Flee_OnExit);
	//	STATE_SPAWN,
	p_StateMachine->RegisterState(STATE_SPAWN, &AHunter::State_Spawn_OnEnter, &AHunter::State_Spawn_OnTick, &AHunter::State_Spawn_OnExit);
	//	STATE_DIE,
	p_StateMachine->RegisterState(STATE_DIE, &AHunter::State_Die_OnEnter, &AHunter::State_Die_OnTick, &AHunter::State_Die_OnExit);
	//	STATE_HIT,
	p_StateMachine->RegisterState(STATE_HIT, &AHunter::State_Hit_OnEnter, &AHunter::State_Hit_OnTick, &AHunter::State_Hit_OnExit);
	//STATE_HUNTER_CHASE
	p_StateMachine->RegisterState(STATE_HUNTER_CHASE, &AHunter::State_Chase_OnEnter, &AHunter::State_Chase_OnTick, &AHunter::State_Chase_OnExit);
	//STATE_HUNTER_TOMATE
	p_StateMachine->RegisterState(STATE_HUNTER_CHASE, &AHunter::State_Chase_OnEnter, &AHunter::State_Chase_OnTick, &AHunter::State_Chase_OnExit);


}

void AHunter::State_Wander_OnEnter(void){	Super::State_Wander_OnEnter();}

void AHunter::State_Wander_OnTick(float f_DeltaTime)
{
	Super::State_Wander_OnTick(f_DeltaTime);
	//TArray<FHitResult> hitResult = getSurroundings();
	//ACreature* tempPrayTarget = getPray(&hitResult);
	////chase if there's a pray and it's not meet from last time, chase that target.
	//if (tempPrayTarget != nullptr) {
	//	if (prayTarget != tempPrayTarget && tempPrayTarget != this) {
	//		prayTarget = tempPrayTarget;
	//		cTargetCreature = prayTarget;
	//		p_StateMachine->ChangeState(STATE_HUNTER_CHASE);
	//	}
	//}

}

void AHunter::State_Wander_OnExit(void) { SetLastState(p_StateMachine->GetCurrentState()); }

void AHunter::State_Spawn_OnEnter(void)
{
	Super::State_Spawn_OnEnter();

}

void AHunter::State_Spawn_OnTick(float f_DeltaTime)
{
	Super::State_Spawn_OnTick(f_DeltaTime);
	//spawn new creature
	cGenerator->spawnActortoWorld<AHunter>(genRandomLocation(cPosition, cSize * 2, true, cSize));
	p_StateMachine->ChangeState(STATE_WANDER);
}
void AHunter::State_Spawn_OnExit(void) { SetLastState(p_StateMachine->GetCurrentState()); }

void AHunter::State_Flee_OnTick(float f_DeltaTime)
{
	//if the target is less than its sight's twice or it's not die, keep fleeing
	if (FVector::Distance(cTargetCreature->GetPos(), cPosition)<(cSight * 1.5) && cTargetCreature != nullptr) {
	//get the target's position and get the fleeing direction
		cTargetPosition = cPosition - cTargetCreature->GetPos();
		//and let the actor move
		move(f_DeltaTime, true);
	}
	else {
		//otherwise get back to last state
		p_StateMachine->ChangeState(cLastState);
	}

}
void AHunter::State_Flee_OnExit(void) { SetLastState(p_StateMachine->GetCurrentState()); }

void AHunter::State_Hit_OnTick(float f_DeltaTime)
{
	//if time's up, change the status back to normal(might be overloaded when needed.
	if (cTimer >= cTime) {
		p_StateMachine->ChangeState(cLastState);
	}
	else {
		cTimer += f_DeltaTime;
	}

}

void AHunter::State_Hit_OnExit(void) { SetLastState(p_StateMachine->GetCurrentState()); }

void AHunter::State_Chase_OnEnter(void)
{
	cTargetPosition = prayTarget->GetPos();
	//set the chasing time be 3s
	cTime = 3.f;
	//reset the timer
	cTimer = 0.f;
}

void AHunter::State_Chase_OnTick(float f_DeltaTime)
{
	cTargetPosition = prayTarget->GetPos();
		//and let the actor move
	move(f_DeltaTime, true);

		//when hunter really nearby the target, both of them get hit and both shall changed to hit state
	if (FVector::Distance(cTargetPosition, cPosition) <= (cSize*1.5) && prayTarget != nullptr) {
		//take some recovery before taking damage
		int recover = prayTarget->GetHP() - cPower + prayTarget->GetDef();
		//both take damage
		prayTarget->TakeDmg(cPower, cPosition);
		//before hunter take damage, recover HP based on the damage the target takes
		//but 1/2 of it.<==tweak to just 1/1
		//recover -= cTargetCreature->GetHP();
		cHP += (recover);//2/
		TakeDmg(cTargetCreature->GetPower(), prayTarget->GetPos());
		//and make a force toward each other
			//todo
		//if it kills the creature, add a counter
		//if the count is reached the spawn count, it'll spawn a new hunter
		if (prayTarget->GetHP() <= 0) {
			killCount += 1;
			totalKillCount += 1;
			if (killCount >= cSpawnCount) {
				isMating = true;
			}
		}

	}
}

void AHunter::State_Chase_OnExit(void){	SetLastState(p_StateMachine->GetCurrentState());}

void AHunter::State_ToMate_OnEnter(void)
{
	cTargetPosition = mateTarget->GetPos();
	//set the chasing time be 3s
	cTime = 3.f;
	//reset the timer
	cTimer = 0.f;

}

void AHunter::State_ToMate_OnTick(float f_DeltaTime)
{
	cTargetPosition = mateTarget->GetPos();
	//and let the actor move
	move(f_DeltaTime, true);

	//when hunter really nearby the target, both of them will send the pointer itself to the controler and make a  series of genome breeding and spawn various of new hunters
	if (FVector::Distance(cTargetPosition, cPosition) <= (cSize) && mateTarget != nullptr) {
		//mate operation, the process automatacally operated by the controler.
		DNAController->setGenomeCouple(this, globalTimer, totalKillCount);
		//finish mating, turn it back to false.
		isMating = false;

	}
}

void AHunter::setController(FString inAttr)
{
	//get the controler actor with the correcct attribute string.
	for (TActorIterator<AEvolutionControler> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AEvolutionControler* tempController = *ActorItr;
		// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
		if (tempController->ServingType == inAttr) {
			DNAController = *ActorItr;
		}
	}

}

float AHunter::neuroDecide(ACreature * inPray, AHunter * inMate, bool isOvertime)
{
	TArray<double> inputDecide;

	//prayValue: is pray existed or not
	int prayValue = 0;
	//if inPray is not null(aka. found pray), change it to 1.
	if (inPray != nullptr) {
		prayValue++;
	}
	inputDecide.Push(prayValue);

	//mateValue: is mateExisted or not
		//if inMate is not null(aka. found Mate), change it to 1.
	int mateValue = 0;
	if (inMate != nullptr) {
		mateValue++;
	}
	inputDecide.Push(mateValue);

	//isOvertimeValue: is chasing/mating action overtimed?
			//if it's overtimed is not null(aka. giving up), change it to 1.
	int isOvertimeValue = 0;
	if (isOvertime) {
		isOvertimeValue++;
	}
	inputDecide.Push(isOvertimeValue);
	return DNAController->NeuronDecision(inputDecide);
}



double AHunter::realizeDecision(double inDecision, ACreature * inPray, AHunter * inMate, bool isOvertime)
{
	int adjustDecision = 0;
	//state id: 0:wander, 1:chase, 2:toMate
	int decision = round(inDecision);
	//if decision is more than 5 or less than 0, it means it's an invalid decision and turn it to wander
	//otherwise look its value is correct or not
	

	//if there's no mate or got mate but overtime, keep it to wander as it's unable to mate 
	if (decision == 2) {
		if (inMate != nullptr) {
			if (!isOvertime) {
				adjustDecision = 2;
			}
		}
	}
	//if there's no pray in the sight,
	else if (decision == 1) {
		if (inPray != nullptr) {
			if (!isOvertime) {
				adjustDecision = 1;
			}
		}
	}
	return adjustDecision;
}
