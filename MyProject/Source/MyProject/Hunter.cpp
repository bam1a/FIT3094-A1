// Fill out your copyright notice in the Description page of Project Settings.

#include "Hunter.h"

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
	//prepare decision parameters
	TArray<FHitResult> hitResult = getSurroundings();
	//find pray is existed or not
	ACreature* tempPrayTarget = getPray(&hitResult);
	//find mating target is existed or not
	AHunter* tempMateTarget = getMate(&hitResult);
	//find the timer is over or not when it's in chasing state
	isOvertime();
	//find if the creature is dead or not
	bool isDead = (cHP <= 0);
	bool isDamaged = (cHP <= previousHP);
	//make decision
	neuroDecide(tempPrayTarget,tempMateTarget,isDead,isDamaged,isOvertime());
	//verify decision is viable

	//do the state machine tick operations
	p_StateMachine->Tick(DeltaTime);
	

	//update the previous HP as current HP after making decision

}

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
	//if HP is less than 0, change state to die.
	if (cHP <= 0) {
		p_StateMachine->ChangeState(STATE_DIE);//<--problem
	}
	else {
		p_StateMachine->ChangeState(STATE_HIT);//<--problem
	}

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
	//initialize the parameeter
	initialize(15, 100.f, 25, 10, 15, 300.f);
	//initialize();
	cType = HUNTER;

	//set target chasing time and the kill count
	chaseTime = 30.f;
	killCount = 0;
	cSpawnCount = FMath::RandRange(2,5);
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
	return nullptr;
}

bool AHunter::isOvertime()
{
	return false;
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
	cTargetPosition = cTargetCreature->GetPos();
	cTimer = 0.f;
}

void AHunter::State_Chase_OnTick(float f_DeltaTime)
{
	//if the timer is over, or the target is gone, hunter lose the interest and find another target.
	if (cTimer >= chaseTime||cTargetCreature==nullptr) {
		prayTarget = nullptr;
		p_StateMachine->ChangeState(STATE_WANDER);
	}
	//otherwise move the target and beat it if touched
	else {
		cTimer += f_DeltaTime;
		cTargetPosition = cTargetCreature->GetPos();
		//and let the actor move
		move(f_DeltaTime, true);

		//when hunter really nearby the target, both of them get hit and both shall changed to hit state
		if (FVector::Distance(cTargetPosition, cPosition) <= (cSize*1.5)&&cTargetCreature!=nullptr) {
			//take some recovery before taking damage
			int recover = cTargetCreature->GetHP()-cPower+cTargetCreature->GetDef();
			//both take damage
			cTargetCreature->TakeDmg(cPower, cPosition);
			//before hunter take damage, recover HP based on the damage the target takes
			//but 1/2 of it.<==tweak to just 1/1
			//recover -= cTargetCreature->GetHP();
			cHP += (recover);//2/
			TakeDmg(cTargetCreature->GetPower(), cTargetCreature->GetPos());
			//and make a force toward each other
				//todo
			//if it kills the creature, add a counter
			//if the count is reached the spawn count, it'll spawn a new hunter
			if (cTargetCreature->GetHP() <= 0) {
				killCount += 1;
				if (killCount >= cSpawnCount) {
					p_StateMachine->ChangeState(STATE_SPAWN);
					//then reset the count.
					killCount = 0;
				}
			}
			
		}
		//when the pray is over its sight, change it back to wander and clear the target
		else if (FVector::Distance(cTargetPosition, cPosition) >= (cSight*2) || cTargetCreature == nullptr) {
			p_StateMachine->ChangeState(STATE_WANDER);
			prayTarget = nullptr;
		}



	}
}

void AHunter::State_Chase_OnExit(void){	SetLastState(p_StateMachine->GetCurrentState());}

float AHunter::neuroDecide(ACreature * inPray, AHunter * inMate, bool isDead, bool isDamaged, bool isOvertime)
{
	return 0.0f;
}
