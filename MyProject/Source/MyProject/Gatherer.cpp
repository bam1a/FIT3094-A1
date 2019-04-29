// Fill out your copyright notice in the Description page of Project Settings.

#include "Gatherer.h"

void AGatherer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
