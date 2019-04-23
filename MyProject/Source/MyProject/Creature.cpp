// Fill out your copyright notice in the Description page of Project Settings.

#include "Creature.h"

// Sets default values
ACreature::ACreature()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//we want our RootComponent to be the mesh(We will be applying physics to it)
	RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	//get the shape of our Enemy from within the starter content folder
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Wedge(TEXT("/game/StarterContent/Shapes/Shape_Wedge_A.Shape_Wedge_A"));

	//andset our Mesh property to reference the RootComponent
	Mesh = Cast<UStaticMeshComponent>(RootComponent);
	//set our shape as the static mesh, and turn our Physics on.
	Mesh->SetStaticMesh(Wedge.Object);
	Mesh->SetSimulatePhysics(true);

	//StateMachine setup and register
	//do it in new function as it'll be inherited by others
	stateRegister();


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

	m_StateMachine->Tick(DeltaTime);


}

// Called to bind functionality to input
void ACreature::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

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

	//set default state
//	m_StateMachine->ChangeState(STATE_STANDBY);

}

void ACreature::State_Wander_OnEnter(void) {}
void ACreature::State_Wander_OnTick(float f_DeltaTime){}
void ACreature::State_Wander_OnExit(void){ SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Flee_OnEnter(void){}
void ACreature::State_Flee_OnTick(float f_DeltaTime){}
void ACreature::State_Flee_OnExit(void){ SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Spawn_OnEnter(void){}
void ACreature::State_Spawn_OnTick(float f_DeltaTime){}
void ACreature::State_Spawn_OnExit(void){ SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Die_OnEnter(void){}
void ACreature::State_Die_OnTick(float f_DeltaTime){}
void ACreature::State_Die_OnExit(void){ SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Hit_OnEnter(void){}
void ACreature::State_Hit_OnTick(float f_DeltaTime){}
void ACreature::State_Hit_OnExit(void){ SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Standby_OnEnter(void){}
void ACreature::State_Standby_OnTick(float f_DeltaTime){}
void ACreature::State_Standby_OnExit(void){ SetLastState(m_StateMachine->GetCurrentState()); }
