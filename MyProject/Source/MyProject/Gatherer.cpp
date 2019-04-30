// Fill out your copyright notice in the Description page of Project Settings.

#include "Gatherer.h"

void AGatherer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGatherer::BeginPlay()
{
	Super::Super::BeginPlay();

	setPathfinder();
	//initialize the parameeter
	initialize();

	//set default state
	m_StateMachine->ChangeState(STATE_WANDER);

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
	m_StateMachine = new StateMachine<Creature_State, AGatherer>(this, STATE_DO_NOTHING);
	//STATE_WANDER,
	m_StateMachine->RegisterState(STATE_WANDER, &AGatherer::State_Wander_OnEnter, &AGatherer::State_Wander_OnTick, &AGatherer::State_Wander_OnExit);
	//	STATE_FLEE,
	m_StateMachine->RegisterState(STATE_FLEE, &AGatherer::State_Flee_OnEnter, &AGatherer::State_Flee_OnTick, &AGatherer::State_Flee_OnExit);
	//	STATE_SPAWN,
	m_StateMachine->RegisterState(STATE_SPAWN, &AGatherer::State_Spawn_OnEnter, &AGatherer::State_Spawn_OnTick, &AGatherer::State_Spawn_OnExit);
	//	STATE_DIE,
	m_StateMachine->RegisterState(STATE_DIE, &AGatherer::State_Die_OnEnter, &AGatherer::State_Die_OnTick, &AGatherer::State_Die_OnExit);
	//	STATE_HIT,
	m_StateMachine->RegisterState(STATE_HIT, &AGatherer::State_Hit_OnEnter, &AGatherer::State_Hit_OnTick, &AGatherer::State_Hit_OnExit);
	//	STATE_STANDBY
	m_StateMachine->RegisterState(STATE_STANDBY, &AGatherer::State_Standby_OnEnter, &AGatherer::State_Standby_OnTick, &AGatherer::State_Standby_OnExit);
	//	STATE_COLLECTOR_TOEAT
	m_StateMachine->RegisterState(STATE_COLLECTOR_TOEAT, &AGatherer::State_ToEat_OnEnter, &AGatherer::State_ToEat_OnTick, &AGatherer::State_ToEat_OnExit);
	//	STATE_COLLECTOR_EATING
	m_StateMachine->RegisterState(STATE_COLLECTOR_EATING, &AGatherer::State_Eating_OnEnter, &AGatherer::State_Eating_OnTick, &AGatherer::State_Eating_OnExit);

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
		m_StateMachine->ChangeState(STATE_COLLECTOR_TOEAT);
	}
	if (tempHunterTarget != nullptr) {
		cTargetCreature = Cast<ACreature>(tempHunterTarget);
		m_StateMachine->ChangeState(STATE_FLEE);
	}
}

void AGatherer::State_Wander_OnExit(void)
{	
	Super::State_Wander_OnExit();
}

void AGatherer::State_Spawn_OnEnter(void)
{
	Super::State_Spawn_OnEnter();
}

void AGatherer::State_Spawn_OnTick(float f_DeltaTime)
{
	Super::State_Spawn_OnTick(f_DeltaTime);
}

void AGatherer::State_Spawn_OnExit(void)
{
	Super::State_Spawn_OnExit();
}

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
			m_StateMachine->ChangeState(STATE_COLLECTOR_EATING);
		}
		else {
			cPathlistID -= 1;
			cTargetPosition = cPathlist[cPathlistID];
		}
	}
	//if foodTarget is eaten(should be result in being a null pointer), change it back to wander state.
	if (foodTarget == nullptr) {
		m_StateMachine->ChangeState(STATE_WANDER);
	}
	//if hunter is on its sight, flee.
	TArray<FHitResult> hitResult = getSurroundings();
	AHunter* tempHunterTarget = getHunter(&hitResult);
	if (tempHunterTarget != nullptr) {
		cTargetCreature = Cast<ACreature>(tempHunterTarget);
		m_StateMachine->ChangeState(STATE_FLEE);
	}


	//and let the actor move
	move(f_DeltaTime, false);

}

void AGatherer::State_ToEat_OnExit(void) { SetLastState(m_StateMachine->GetCurrentState()); }

void AGatherer::State_Eating_OnEnter(void)
{
}

void AGatherer::State_Eating_OnTick(float f_DeltaTime)
{
	//kill the target food when reached the target.
	foodTarget->BeEaten();
	//add happiness and hp when eaten the food
	happiness += 1;
	cHP += 1;
	//check if it reaches the happiness limit, spawn a new same type creature when reached, otherwise just do the wander
	if (happiness == happinessLimit) {
		m_StateMachine->ChangeState(STATE_SPAWN);
	}
	else {
		m_StateMachine->ChangeState(STATE_WANDER);
	}
}

void AGatherer::State_Eating_OnExit(void) { SetLastState(m_StateMachine->GetCurrentState()); }
