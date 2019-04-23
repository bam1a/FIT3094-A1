// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StateMachine.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Creature.generated.h"


UCLASS()
class MYPROJECT_API ACreature : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties

	//Creature_Status: states the creatures in enum form for state machine
	enum Creature_State {
		STATE_DO_NOTHING = 0,
		STATE_WANDER,
		STATE_FLEE,
		STATE_SPAWN,
		STATE_DIE,
		STATE_HIT,
		STATE_STANDBY
	};

	enum Creature_Type {
		CREATURE = 0,
		COLLECTOR,
		HUNTER,
		HIDER
	};

	ACreature();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//assessor: returning enemycurrent state
	Creature_State SetCurrentState() {
		return m_StateMachine->GetCurrentState();
	}
	//mutator: set enemy current state
	void SetCurrState(Creature_State state) {
		m_StateMachine->ChangeState(state);
	}

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;
	float speed = 10.f;

	StateMachine<Creature_State, ACreature>* m_StateMachine;

	//creature type
	Creature_Type creatureType;
	//parameters
	/*
	speed: creature speed
	power: attacking power
	HP:heart point
	generation: reproduced generation(I guess it might be interesting when generation is being better and better, but it's more like an label, or being abandoned)
	reproduceCount: determines how many child would be generated when spawning new creatures.
	pathNode:the node will be going to
	targetNodeID: the node in the pathNode array will be going to
	targetPosition: the position targeting at
	position: current position(actually can replaced by GetActorByLocation but just in case.
	*/
	float speed, power;
	int HP, generation,reproduceCount;
	FVector position;
	//TArray<Node> pathNode;
	//int targetNodeID;
	//FVector targetPosition;


protected:
	//state machine's state events

	//STATE_DO_NOTHING:doing nothing
	virtual void State_Nothing_OnEnter(void);
	virtual void State_Nothing_OnTick(float f_DeltaTime);
	virtual void State_Nothing_OnExit(void);
	//STATE_WANDER:wandering in another place(will be overwriten by others but will act as a super::blah(blah) )
	virtual void State_Wander_OnEnter(void);
	virtual void State_Wander_OnTick(float f_DeltaTime);
	virtual void State_Wander_OnExit(void);
	//STATE_FLEE:fleeing
	virtual void State_Flee_OnEnter(void);
	virtual void State_Flee_OnTick(float f_DeltaTime);
	virtual void State_Flee_OnExit(void);
	//STATE_SPAWN: spawning new creature based on its status but with some varieties based on some randomness
	virtual void State_Spawn_OnEnter(void);
	virtual void State_Spawn_OnTick(float f_DeltaTime);
	virtual void State_Spawn_OnExit(void);
	//STATE_DIE:die (remove itself from render pipeline array and destory itself.)
	virtual void State_Die_OnEnter(void);
	virtual void State_Die_OnTick(float f_DeltaTime);
	virtual void State_Die_OnExit(void);
	//STATE_HIT:hit by something( might have some time lag)
	virtual void State_Hit_OnEnter(void);
	virtual void State_Hit_OnTick(float f_DeltaTime);
	virtual void State_Hit_OnExit(void);
	//STATE_STANDBY:standby(hider might able having some specific feature)
	virtual void State_Standby_OnEnter(void);
	virtual void State_Standby_OnTick(float f_DeltaTime);
	virtual void State_Standby_OnExit(void);

};