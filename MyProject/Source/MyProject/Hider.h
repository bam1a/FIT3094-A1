// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creature.h"
#include "Hunter.h"
#include "Shelter.h"
#include "Hider.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AHider : public ACreature
{
	GENERATED_BODY()
public:
	AHider();
	//constructor with a target shelter, make sure it won't hide at that shelter when hiding.
	AHider(FVector inPos, AShelter* inShelter);
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
	AShelter* shelterTarget;
	float hideTime;

	//hider only function
	//functions for get the surrounding actors in the sight
	//getShelter: detect shelter in the sight
	//getHunter: detect predator in the sight
	AShelter* getShelter(TArray<FHitResult>* inHits);
	ACreature* getCreature(TArray<FHitResult>* inHits);

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
	//STATE_STANDBY: stay at a position with spawn timing and detecting hunter
	virtual void State_Standby_OnEnter(void);
	virtual void State_Standby_OnTick(float f_DeltaTime);
	virtual void State_Standby_OnExit(void);
	//STATE_HIDER_TOSHELTER: move to the shelter by path finding
	void State_ToShelter_OnEnter(void);
	void State_ToShelter_OnTick(float f_DeltaTime);
	void State_ToShelter_OnExit(void);

	//this gatherer is special for creature's functionality, using h as the first letter to prevent confusion between the original m_StateMachine and others.
	StateMachine<Creature_State, AHider>* h_StateMachine;

};
