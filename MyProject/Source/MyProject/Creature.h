// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StateMachine.h"
#include "PathNode.h"
#include "Pathfind.h"
#include "CoreMinimal.h"
#include "ConstructorHelpers.h"
#include <EngineGlobals.h>
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
		STATE_STANDBY,
		STATE_COLLECTOR_TOEAT,
		STATE_COLLECTOR_EATING,
		STATE_HIDER_TOSHELTER
	};

	static enum Creature_Type {
		CREATURE = 0,
		GATHERER,
		HUNTER,
		HIDER
	};

	//create a blank creature without anything started
	ACreature();
	//initialize without parameters?
	void initialize();
	//initialize with parameters
	void initialize(float inSpeed, float inSize, int inPower, int inDef, int inHP, float inSight, FVector inPos);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//function for setting the path finder class
	void setPathfinder();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//externally do when creature intetionally hit other
		//when no more damage, will be kill itself from the screen.
	void TakeDmg(int inAtk);

	//assessor:
	//current state
	Creature_State SetCurrentState() {
		return m_StateMachine->GetCurrentState();
	}
	//speed
	float GetSpeed() { return cSpeed; };
	//size
	float GetSize() { return cSize; };
	//Power
	int GetPower() { return cPower; };
	//def
	int GetDef() { return cDef; }
	//HP
	int GetHP() { return cHP; };
	//sight
	float GetSight() { return cSight; };
	//generation
	int GetGen() { return cGen; };
	//reproduction count
	int GetSpawnCount() { return cSpawnCount; };
	//position
	FVector GetPos() { return cPosition; };
	//last state
	Creature_State GetLastState() { return cLastState; };

	//mutator:
	//current state
	void SetCurrState(Creature_State state) {
		m_StateMachine->ChangeState(state);
	}
	//speed
	void SetSpeed(float inSpeed) { cSpeed = inSpeed; };
	//Power
	void SetPower(int inPower) { cPower = inPower; };
	//HP
	void SetHP(int inHP) { cHP = inHP; };
	//size
	void SetSize(float inSize) { cSize = inSize; };
	//def
	void SetDef(int inDef) { cDef = inDef; };
	//sight
	void SetSight(int inSight) { cSight = inSight; };
	//generation
	void SetGen(int inGen) { cGen = inGen; };
	//reproduction count
	void SetSpawnCount(int inCount) { cSpawnCount = inCount; };
	//position
	void SetPosition(FVector inPos) { cPosition = inPos; };
	//last state
	void SetLastState(Creature_State inState) { cLastState = inState; };


private:

protected:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	UMaterialInstanceDynamic* DynamicMaterialInst;

	StateMachine<Creature_State, ACreature>* m_StateMachine;


	virtual void stateRegister();


	//creature type
	Creature_Type creatureType;
	//parameters
	/*
	core parameters:
	cSpeed: creature speed, (Affects movement speed positively)
	cPower: attacking power
	cHP:heart point
	cSize: size (Affects movement speed negatively[friction?] + the size radius of itself.)
	cDef: natural defences
	cSight: range of sight

	other parameters:
	cGen: reproduced generation(I guess it might be interesting when generation is being better and better, but it's more like an label, or being abandoned)
	cReproduceCount: determines how many child would be generated when spawning new creatures.
	cPathList:the node will be going to
	cPathListID: the current ID of the path.
	cTargetNodeID: the node in the pathNode array will be going to
	cTargetPosition: the position targeting at
	cPosition: current position(actually can replaced by GetActorByLocation but just in case.
	cVelocity: the velocity vector of the creature
	cLastState: last state
	cTargetCreature: the fleeing/attacking target
	cTimer: the increment timer for different kind of use(eg: hit lag, etc.), 1 second=1.0f.
	cTime: the target time of the timer
	*/
	float cSpeed, cSize, cSight, cTimer, cTime;
	int cPower, cHP, cDef, cGen, cSpawnCount;
	UPROPERTY(VisibleAnywhere)
		int cPathlistID;

	FVector cPosition, cTargetPosition, cLastPosition, cVelocity;
	Creature_State cLastState;
	Creature_Type cType;
	ACreature* cTargetCreature;
	UPROPERTY(EditAnywhere)
		TArray<FVector> cPathlist;
	//int cTargetNodeID;
	UPROPERTY(VisibleAnywhere, Category="pathFinding")
	APathfind* cPathfinder;
	/////////////////////////////////////////////////////////////////////////////////////////
	//state machine's state events

	//STATE_DO_NOTHING:doing nothing
	//void State_Nothing_OnEnter(void);
	//void State_Nothing_OnTick(float f_DeltaTime);
	//void State_Nothing_OnExit(void);
	//STATE_WANDER:wandering in another place(will be overwriten by others but will act as a super::blah(blah) ) <--target, after finishing up the node properties
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
	void State_Die_OnEnter(void);
	void State_Die_OnTick(float f_DeltaTime);
	void State_Die_OnExit(void);
	//STATE_HIT:hit by something and determine is dead or not( might have some time lag)
	virtual void State_Hit_OnEnter(void);
	virtual void State_Hit_OnTick(float f_DeltaTime);
	virtual void State_Hit_OnExit(void);
	//STATE_STANDBY:standby(hider might able having some specific feature)
	virtual void State_Standby_OnEnter(void);
	virtual void State_Standby_OnTick(float f_DeltaTime);
	virtual void State_Standby_OnExit(void);


	//////////////////Collector only:define the function in  collector.//////////////////////////


	//other functions
	FVector genRandomLocation(FVector initPos, float inRange, bool isNeedValidCheck=false, float inCheckRange=1.f);
	void move(float DeltaTime, bool isDash);
	bool checkPosValid(FVector checkPos, float sweepArea);
	TArray<FHitResult> getSurroundings();

};