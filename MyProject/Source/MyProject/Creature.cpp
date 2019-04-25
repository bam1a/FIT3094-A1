// Fill out your copyright notice in the Description page of Project Settings.

#include "Creature.h"
#include "Wall.h"
#include "ConstructorHelpers.h"
#include <EngineGlobals.h>
#include "DrawDebugHelpers.h"
#include "Engine/GameEngine.h"


// Sets default values
ACreature::ACreature()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//we want our RootComponent to be the mesh(We will be applying physics to it)
	RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	//get the shape of our Enemy from within the starter content folder
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> Wedge(TEXT("/game/StarterContent/Shapes/Shape_Wedge_A.Shape_Wedge_A"));
	//andset our Mesh property to reference the RootComponent
	Mesh = Cast<UStaticMeshComponent>(RootComponent);

	//set our shape as the static mesh, and turn our Physics on.
	//Mesh->SetStaticMesh(Wedge.Object);
	Mesh->SetSimulatePhysics(true);

	initialize();


}

void ACreature::initialize()
{
	cSpeed = 10.f;
	cSize = 10.f;
	cPower = 10;
	cDef = 10;
	cHP = 10;
	cSight = 10.f;

	cPosition = GetActorLocation();
	//set position (last position should be same in this moment)
	cLastPosition = cPosition;

	//StateMachine setup and register
	//do it in new function as it'll be inherited by others
	stateRegister();

	//set default state
	m_StateMachine->ChangeState(STATE_WANDER);

}

void ACreature::initialize(float inSpeed, float inSize, int inPower, int inDef, int inHP, float inSight, FVector inPos)
{
	cSpeed = inSpeed;
	cSize = inSize;
	cPower = inPower;
	cDef = inDef;
	cHP = inHP;
	cSight = inSight;

	SetActorLocation(inPos);
	cPosition = GetActorLocation();
	//set position (last position should be same in this moment)
	cLastPosition = cPosition;

	//StateMachine setup and register
	//do it in new function as it'll be inherited by others
	stateRegister();

	//set default state
	m_StateMachine->ChangeState(STATE_WANDER);


}

// Called when the game starts or when spawned
void ACreature::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACreature::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//get the velocity by checking the last and current position
	cVelocity = cPosition - cLastPosition;
	cVelocity = cVelocity / DeltaTime;
	//as it's a 2d plane, force the velocity of z axis only be 0.
	cVelocity.Z = 0.f;

	//update the position and last position parameter
	cLastPosition = cPosition;
	cPosition = GetActorLocation();

	//do the state machine tick operations
	m_StateMachine->Tick(DeltaTime);


}

// Called to bind functionality to input
void ACreature::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

FVector ACreature::genRandomLocation(FVector initPos, float inRange)
{
	FVector outVector;
	outVector.X = initPos.X + FMath::FRandRange((inRange*-1.f), inRange);
	outVector.Y = initPos.Y + FMath::FRandRange((inRange*-1.f), inRange);
	outVector.Z = 0.f;
	//check if the location is valid, if not do it until it's valid<--maybe in a new function?
	return outVector;
}

void ACreature::move(float DeltaTime, bool isDash)
{

	float finalSpeed = cSpeed / cSize * 200.f;
	//if it's dashing, the speed will be twiced
	if (isDash) {
		finalSpeed *= 2.f;
	}

	//set the location
		//if there's has the route, run by each node
	SetActorLocation(FMath::VInterpConstantTo(cPosition, cTargetPosition, DeltaTime, finalSpeed));
	
	//set the rotation
	SetActorRotation(cVelocity.Rotation());

}

void ACreature::stateRegister()
{
	m_StateMachine = new StateMachine<Creature_State, ACreature>(this, STATE_DO_NOTHING);
	//STATE_WANDER,
	m_StateMachine->RegisterState(STATE_WANDER, &ACreature::State_Wander_OnEnter, &ACreature::State_Wander_OnTick, &ACreature::State_Wander_OnExit);
	//	STATE_FLEE,
	m_StateMachine->RegisterState(STATE_FLEE, &ACreature::State_Flee_OnEnter, &ACreature::State_Flee_OnTick, &ACreature::State_Flee_OnExit);
	//	STATE_SPAWN,
	m_StateMachine->RegisterState(STATE_SPAWN, &ACreature::State_Spawn_OnEnter, &ACreature::State_Spawn_OnTick, &ACreature::State_Spawn_OnExit);
	//	STATE_DIE,
	m_StateMachine->RegisterState(STATE_DIE, &ACreature::State_Die_OnEnter, &ACreature::State_Die_OnTick, &ACreature::State_Die_OnExit);
	//	STATE_HIT,
	m_StateMachine->RegisterState(STATE_HIT, &ACreature::State_Hit_OnEnter, &ACreature::State_Hit_OnTick, &ACreature::State_Hit_OnExit);
	//	STATE_STANDBY
	m_StateMachine->RegisterState(STATE_STANDBY, &ACreature::State_Standby_OnEnter, &ACreature::State_Standby_OnTick, &ACreature::State_Standby_OnExit);


}

void ACreature::State_Wander_OnEnter(void) {
	//generate a target location
	cTargetPosition = genRandomLocation(FVector::ZeroVector, 2000.f);

}
void ACreature::State_Wander_OnTick(float f_DeltaTime) {
	//if creature arrive nearby the location, change another random location
	//maybe also if the path array length is not zero, and the index is the last node, will be find a new path
	FVector vectorToTarget = cTargetPosition - cPosition;

	if (FVector::Distance(cTargetPosition, cPosition)<100.f) {
		cTargetPosition = genRandomLocation(FVector::ZeroVector, 2000.f);
	}

	//and let the actor move
	move(f_DeltaTime, false);
}
void ACreature::State_Wander_OnExit(void) { SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Flee_OnEnter(void) {}
void ACreature::State_Flee_OnTick(float f_DeltaTime) {
	//if the target is less than its sight's twice or it's not die, keep fleeing
	if (FVector::Distance(cTargetCreature->GetPos(), cPosition)>(cSight * 2) || cTargetCreature != nullptr) {
		//get the target's position and get the fleeing direction
		cTargetPosition = cPosition - cTargetCreature->GetPos();
		//and let the actor move
		move(f_DeltaTime, true);
	}
	//otherwise get back to wandering mode.
	m_StateMachine->ChangeState(STATE_WANDER);

}
void ACreature::State_Flee_OnExit(void) { SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Spawn_OnEnter(void) {}
//generate a new same creature with a slightly different status based on parent status.
//do it in different creature types.
void ACreature::State_Spawn_OnTick(float f_DeltaTime) {}
void ACreature::State_Spawn_OnExit(void) { SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Die_OnEnter(void) {}
void ACreature::State_Die_OnTick(float f_DeltaTime) {
	Destroy();
}
void ACreature::State_Die_OnExit(void) { SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Hit_OnEnter(void) {
	//reset the timer
	cTimer = 0.f;
}
void ACreature::State_Hit_OnTick(float f_DeltaTime) {
	//set the lag time be 3s
	cTime = 3.f;
	//if time's up, change the status back to normal(might be overloaded when needed.
	if (cTimer >= cTime) {
		m_StateMachine->ChangeState(cLastState);
	}
	else {
		cTimer += f_DeltaTime;
	}
}
void ACreature::State_Hit_OnExit(void) { SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Standby_OnEnter(void) {}
void ACreature::State_Standby_OnTick(float f_DeltaTime) {}//this function is mainly used for hider for keep staying it in place and do some operation in some cond.
void ACreature::State_Standby_OnExit(void) { SetLastState(m_StateMachine->GetCurrentState()); }
