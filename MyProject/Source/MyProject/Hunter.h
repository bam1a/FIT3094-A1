// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creature.h"
#include "Hunter.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AHunter : public ACreature
{
	GENERATED_BODY()
public:
	AHunter();
	AHunter(FVector inPos);
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
	int killCount;
	ACreature* prayTarget;
	float chaseTime;

	//Hunter only function
	//functions for get the surrounding actors in the sight
	ACreature* getPray(TArray<FHitResult>* inHits);

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
	//STATE_HUNTER_CHASE: chasing the pray creature
	void State_Chase_OnEnter(void);
	void State_Chase_OnTick(float f_DeltaTime);
	void State_Chase_OnExit(void);

	//this gatherer is special for creature's functionality, using p as the first letter to prevent confusion between the original m_StateMachine and others.
	StateMachine<Creature_State, AHunter>* p_StateMachine;


};
