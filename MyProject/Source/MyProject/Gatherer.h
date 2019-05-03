// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creature.h"
#include "Food.h"
#include "Hunter.h"
#include "Gatherer.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AGatherer : public ACreature
{
	GENERATED_BODY()
public:
	AGatherer();
	AGatherer(FVector inPos);
	virtual void Tick(float DeltaTime) override;

	//externally do when creature intetionally hit other
	//when no more damage, will be kill itself from the screen.
	virtual void TakeDmg(int inAtk) override;


private:
	//function contains all the construction procedure.
	void construction();
	// Called when the game starts or when spawned
	void BeginPlay() override;

	//local variables
	AFood * foodTarget;
	int happiness, happinessLimit;

	//Gatherer-only functions
	//functions for get the surrounding actors in the sight
	//getfood:detect food in the sight
	//getHunter: detect predator in the sight
	AFood* getFood(TArray<FHitResult>* inHits);
	AHunter* getHunter(TArray<FHitResult>* inHits);
	//getPartner(TArray<FHitResult>* inHits);
	//flockAdjust();

	//registering state, override the whole function without any coherance each other
	virtual void stateRegister() override;

	//STATE_WANDER:wandering in another place(will be overwriten by others but will act as a super::blah(blah) ) <--target, after finishing up the node properties
	virtual void State_Wander_OnEnter(void) override;
	virtual void State_Wander_OnTick(float f_DeltaTime) override;
	virtual void State_Wander_OnExit(void) override;
	//STATE_SPAWN: spawning new creature based on its status but with some varieties based on some randomness
	virtual void State_Spawn_OnEnter(void) override;
	virtual void State_Spawn_OnTick(float f_DeltaTime) override;
	virtual void State_Spawn_OnExit(void) override;
	//STATE_FLEE:fleeing
	virtual void State_Flee_OnTick(float f_DeltaTime)override;
	virtual void State_Flee_OnExit(void)override;
	//STATE_HIT:hit by something and determine is dead or not( might have some time lag)
	virtual void State_Hit_OnTick(float f_DeltaTime)override;
	virtual void State_Hit_OnExit(void)override;
	//STATE_TOEAT: moving towards to the food pallet which detected
	void State_ToEat_OnEnter(void);
	void State_ToEat_OnTick(float f_DeltaTime);
	void State_ToEat_OnExit(void);
	//STATE_EATING: a moment that eating the food pallet
	void State_Eating_OnEnter(void);
	void State_Eating_OnTick(float f_DeltaTime);
	void State_Eating_OnExit(void);

	//this gatherer is special for creature's functionality, using g as the first letter to prevent confusion between the original m_StateMachine.
	StateMachine<Creature_State, AGatherer>* g_StateMachine;

};
