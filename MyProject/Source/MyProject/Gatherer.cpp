// Fill out your copyright notice in the Description page of Project Settings.

#include "Gatherer.h"

AGatherer::AGatherer():ACreature() 
{
	construction();
}

AGatherer::AGatherer(FVector inPos) : ACreature(inPos)
{
	construction();
}

void AGatherer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	g_StateMachine->Tick(DeltaTime); 

}

void AGatherer::TakeDmg(int inAtk, FVector inPosition)
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
		g_StateMachine->ChangeState(STATE_DIE);//<--problem
	}
	else {
		g_StateMachine->ChangeState(STATE_HIT);//<--problem
	}

}

void AGatherer::construction()
{
	//reset all array/pointer content when start up(try prevent memory leakage and crash)
	delete g_StateMachine;
	g_StateMachine = nullptr;
	delete foodTarget;
	foodTarget = nullptr;


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
		DynamicMaterialInst->SetVectorParameterValue(FName(TEXT("Colour")), FLinearColor(0.0, 1.0, 0.0, 1.0));
		Mesh->SetMaterial(0, DynamicMaterialInst);
	}

}

void AGatherer::BeginPlay()
{
	Super::Super::BeginPlay();

	setPathfinder();
	setGenerator();
	//initialize the parameeter
	initialize(10, 100.f, 15, 15, 15, 500.f);
	cType = GATHERER;
	//reproduction counter:randomly from 3-5
	cSpawnCount= FMath::RandRange(3, 5);
	//set default state
	g_StateMachine->ChangeState(STATE_WANDER);

}

AFood * AGatherer::getFood(TArray<FHitResult>* inHits)
{
	//if the hit result array has a food object, output it immediatly.
	for (auto& Hit : *inHits) {
		AFood* food = Cast<AFood>((Hit.GetActor()));
		if (food) {
			return food;
		}
	}
	//otherwise just return a null pointer, other function will recognize.
	return nullptr;
}

AHunter * AGatherer::getHunter(TArray<FHitResult>* inHits)
{
	//if the hit result array has a hunter object, output it immediately.
	for (auto& Hit : *inHits) {
		AHunter* hunter = Cast<AHunter>((Hit.GetActor()));
		if (hunter) {
			return hunter;
		}
	}
	//otherwise just return a null pointer, other function will recognize.
	return nullptr;
}

void AGatherer::stateRegister()
{
	g_StateMachine = new StateMachine<Creature_State, AGatherer>(this, STATE_DO_NOTHING); 
	//STATE_WANDER,
	g_StateMachine->RegisterState(STATE_WANDER, &AGatherer::State_Wander_OnEnter, &AGatherer::State_Wander_OnTick, &AGatherer::State_Wander_OnExit);
	//	STATE_FLEE,
	g_StateMachine->RegisterState(STATE_FLEE, &AGatherer::State_Flee_OnEnter, &AGatherer::State_Flee_OnTick, &AGatherer::State_Flee_OnExit);
	//	STATE_SPAWN,
	g_StateMachine->RegisterState(STATE_SPAWN, &AGatherer::State_Spawn_OnEnter, &AGatherer::State_Spawn_OnTick, &AGatherer::State_Spawn_OnExit);
	//	STATE_DIE,
	g_StateMachine->RegisterState(STATE_DIE, &AGatherer::State_Die_OnEnter, &AGatherer::State_Die_OnTick, &AGatherer::State_Die_OnExit);
	//	STATE_HIT,
	g_StateMachine->RegisterState(STATE_HIT, &AGatherer::State_Hit_OnEnter, &AGatherer::State_Hit_OnTick, &AGatherer::State_Hit_OnExit);
	//	STATE_STANDBY
	g_StateMachine->RegisterState(STATE_STANDBY, &AGatherer::State_Standby_OnEnter, &AGatherer::State_Standby_OnTick, &AGatherer::State_Standby_OnExit);
	//	STATE_COLLECTOR_TOEAT
	g_StateMachine->RegisterState(STATE_COLLECTOR_TOEAT, &AGatherer::State_ToEat_OnEnter, &AGatherer::State_ToEat_OnTick, &AGatherer::State_ToEat_OnExit);
	//	STATE_COLLECTOR_EATING
	g_StateMachine->RegisterState(STATE_COLLECTOR_EATING, &AGatherer::State_Eating_OnEnter, &AGatherer::State_Eating_OnTick, &AGatherer::State_Eating_OnExit);

}

void AGatherer::State_Wander_OnEnter(void)
{
	Super::State_Wander_OnEnter();
}

void AGatherer::State_Wander_OnTick(float f_DeltaTime)
{
	Super::State_Wander_OnTick(f_DeltaTime);
	//make some if cases to find enemies and food
	TArray<FHitResult> hitResult = getSurroundings();
	AFood* tempFoodTarget = getFood(&hitResult);
	AHunter* tempHunterTarget = getHunter(&hitResult);
	if (tempFoodTarget != nullptr) {
		foodTarget = tempFoodTarget;
		g_StateMachine->ChangeState(STATE_COLLECTOR_TOEAT);
	}
	if (tempHunterTarget != nullptr) {
		cTargetCreature = Cast<ACreature>(tempHunterTarget);
		g_StateMachine->ChangeState(STATE_FLEE);
	}
}

void AGatherer::State_Wander_OnExit(void){SetLastState(g_StateMachine->GetCurrentState());}

void AGatherer::State_Spawn_OnEnter(void)
{
	Super::State_Spawn_OnEnter();
}

void AGatherer::State_Spawn_OnTick(float f_DeltaTime)
{
	Super::State_Spawn_OnTick(f_DeltaTime);
	//use the generator to spawn the new actor nearby it
	cGenerator->spawnActortoWorld<AGatherer>(genRandomLocation(cPosition, cSize * 2, true, cSize));
	g_StateMachine->ChangeState(STATE_WANDER);
}

void AGatherer::State_Spawn_OnExit(void){SetLastState(g_StateMachine->GetCurrentState());}

void AGatherer::State_Flee_OnTick(float f_DeltaTime)
{
	//if the target is less than its sight's twice or it's not die, keep fleeing
	if (FVector::Distance(cTargetCreature->GetPos(), cPosition)<(cSight * 1.5) && cTargetCreature != nullptr) {
		//get the target's position and get the fleeing direction
		cTargetPosition = cPosition - cTargetCreature->GetPos();
		//and let the actor move
		move(f_DeltaTime, true);
	}
	else {
		//otherwise get back to wandering mode.
		g_StateMachine->ChangeState(STATE_WANDER);
	}

}

void AGatherer::State_Flee_OnExit(void){SetLastState(g_StateMachine->GetCurrentState());}

void AGatherer::State_Hit_OnTick(float f_DeltaTime)
{
	//if time's up, change the status back to normal(might be overloaded when needed.
	if (cTimer >= cTime) {
		g_StateMachine->ChangeState(cLastState);
	}
	else {
		cTimer += f_DeltaTime;
	}

}

void AGatherer::State_Hit_OnExit(void){SetLastState(g_StateMachine->GetCurrentState());}

void AGatherer::State_ToEat_OnEnter(void)
{
	//cTargetPosition = foodTarget->GetPosition();
	//generate a path of the target
	cPathlist = cPathfinder->GeneratePath(cPosition, foodTarget->GetPosition());
	//set target location to the first index of the path list
	cPathlistID = cPathlist.Num() - 1;
	cTargetPosition = cPathlist[cPathlistID];

}

void AGatherer::State_ToEat_OnTick(float f_DeltaTime)
{
	if (FVector::Distance(cTargetPosition, cPosition) < (cSize)) {
		//change to another index when not finished its path.
		//it reaches the food location, change state to eating.
		if (cTargetPosition == cPathlist[0] || cPathlistID == 0) {
			g_StateMachine->ChangeState(STATE_COLLECTOR_EATING);
		}
		else {
			cPathlistID -= 1;
			cTargetPosition = cPathlist[cPathlistID];
		}
	}
	//if foodTarget is eaten(should be result in being a null pointer), change it back to wander state.
	if (foodTarget == nullptr) {
		g_StateMachine->ChangeState(STATE_WANDER);
	}
	//if hunter is on its sight, flee.
	TArray<FHitResult> hitResult = getSurroundings();
	AHunter* tempHunterTarget = getHunter(&hitResult);
	if (tempHunterTarget != nullptr) {
		cTargetCreature = Cast<ACreature>(tempHunterTarget);
		g_StateMachine->ChangeState(STATE_FLEE);
	}


	//and let the actor move
	move(f_DeltaTime, false);

}

void AGatherer::State_ToEat_OnExit(void) { SetLastState(g_StateMachine->GetCurrentState()); }

void AGatherer::State_Eating_OnEnter(void)
{
}

void AGatherer::State_Eating_OnTick(float f_DeltaTime)
{
	//if the last frame is already eaten by other, just turn it back to wander stat.
	if (foodTarget == nullptr) {
		g_StateMachine->ChangeState(STATE_WANDER);
	}
	else {
		//kill the target food when reached the target.
		foodTarget->BeEaten();
		//add happiness and hp when eaten the food
		happiness += 1;
		cHP += 1;
		//check if it reaches the happiness limit=cSpawnCount, spawn a new same type creature when reached, otherwise just do the wander
		if (happiness >= cSpawnCount) {
			g_StateMachine->ChangeState(STATE_SPAWN);
			//reset the happiness count
			happiness = 0;
		}
		else {
			//find the other
			g_StateMachine->ChangeState(STATE_WANDER);
			//and add 1 happiness count.
	//		happiness += 1;
		}

	}
}

void AGatherer::State_Eating_OnExit(void) { SetLastState(g_StateMachine->GetCurrentState()); }
