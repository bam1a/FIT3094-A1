// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creature.h"
#include "EvolutionControler.h"
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
	virtual void TakeDmg(int inAtk, FVector inPosition) override;
	//get the hunter is looking for mate
	bool getIsMating() { return isMating; };
	void setIsMating(bool inBool) { isMating = inBool; };



private:
	//function contains all the construction procedure.
	void construction();
	// Called when the game starts or when spawned
	void BeginPlay() override;

	//local variables
	int killCount;
	ACreature* prayTarget;
	AHunter* mateTarget;
	bool isMating = false;
	float chaseTime;
	int previousHP;

	//Hunter only function
	//functions for get the surrounding pray in the sight
	ACreature* getPray(TArray<FHitResult>* inHits);
	AHunter* getMate(TArray<FHitResult>* inHits);
	//function
	bool isOvertime();

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

	//STATE_MATING: keep wander until finding the another mating partner and mate it in a random node
	void State_ToMate_OnEnter(void);
	void State_ToMate_OnTick(float f_DeltaTime);
	void State_ToMate_OnExit(void);


	
	/*
	neuron network decision making
	//centralized neuron network, evolve the decision engine (which will be implemented as a controller actor class:P)
	//find how many specific stuff in its surroundings.
	//make decision by using neuron network
	//state id: 0:wander, 2:hit, 3:chase, 4:toMate, 5:die
	this will use an array of 1/0 integer to decide
	*/
	AEvolutionControler* DNAController;
	float currentStateID;
	float neuroDecide(ACreature* inPray, AHunter* inMate, bool isDead, bool isDamaged, bool  isOvertime);
	Creature_State toState(float);

	//check correctness of the current decision and the realized decision
	double verifyDecision(double inDecision, ACreature* inPray, AHunter* inMate, bool isDead, bool isDamaged, bool  isOvertime);
	void realizeDecision(double inExpectedResult);
	//a timer to calculate its fitness
	double globalTimer = 0.f;
	//a value of total killing count to determine its fitness
	int totalKillCount = 0;
	//grab and load the NN format from the file system

	StateMachine<Creature_State, AHunter>* p_StateMachine;


};
