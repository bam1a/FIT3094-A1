// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creature.h"
#include "Food.h"
#include "Gatherer.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AGatherer : public ACreature
{
	GENERATED_BODY()
public:
	void Tick(float DeltaTime) override;


private:

	// Called when the game starts or when spawned
	void BeginPlay() override;

	AFood * eatingTarget;
	int happiness, happinessLimit;

	//Gatherer-only functions
	//function for get the surrounding actors in the sight
	AFood* getFood(TArray<FHitResult>* inHits);
	//APredator* getPredator();
	//getPartner(FHitResult inHitActor);
	//flockAdjust();

	//registering state, override the whole function without any coherance each other
	void stateRegister() override;

	//STATE_WANDER:wandering in another place(will be overwriten by others but will act as a super::blah(blah) ) <--target, after finishing up the node properties
	void State_Wander_OnEnter(void) override;
	void State_Wander_OnTick(float f_DeltaTime) override;
	void State_Wander_OnExit(void) override;
	//STATE_SPAWN: spawning new creature based on its status but with some varieties based on some randomness
	void State_Spawn_OnEnter(void) override;
	void State_Spawn_OnTick(float f_DeltaTime) override;
	void State_Spawn_OnExit(void) override;
	//STATE_TOEAT: moving towards to the food pallet which detected
	void State_ToEat_OnEnter(void);
	void State_ToEat_OnTick(float f_DeltaTime);
	void State_ToEat_OnExit(void);
	//STATE_EATING: a moment that eating the food pallet
	void State_Eating_OnEnter(void);
	void State_Eating_OnTick(float f_DeltaTime);
	void State_Eating_OnExit(void);

	//this gatherer is special for gatherer's functionality.
	StateMachine<Creature_State, AGatherer>* m_StateMachine;

};
