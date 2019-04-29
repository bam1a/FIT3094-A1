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
}

void AGatherer::State_ToEat_OnTick(float f_DeltaTime)
{
}

void AGatherer::State_ToEat_OnExit(void)
{
}

void AGatherer::State_Eating_OnEnter(void)
{
}

void AGatherer::State_Eating_OnTick(float f_DeltaTime)
{
}

void AGatherer::State_Eating_OnExit(void)
{
}
