// Fill out your copyright notice in the Description page of Project Settings.

#include "Creature.h"
#include "Pathfind.h"
#include "Wall.h"
#include "ConstructorHelpers.h"
#include <EngineGlobals.h>
#include <cmath>
#include "DrawDebugHelpers.h"
#include "EngineUtils.h"
#include "Engine/GameEngine.h"

using namespace std;
// Sets default values
ACreature::ACreature()
{
	//reset all array/pointer content when start up(try prevent memory leakage and crash)
	cPathlist.Empty();
	delete cPathfinder;
	cPathfinder = nullptr;
	delete m_StateMachine;
	m_StateMachine = nullptr;
	delete cTargetCreature;
	cTargetCreature = nullptr;

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
	//Mesh->SetSimulatePhysics(true);


}
ACreature::ACreature(FVector inPos) {
	//init. with the original constructor
	ACreature();
	//and also set the creature in specific position.
	SetActorLocation(inPos);

}

void ACreature::initialize()
{
	cSpeed = 10.f;
	cSize = 10.f;
	cPower = 10;
	cDef = 10;
	cHP = 10;
	cSight = 10.f;

	//set its scaling
	Mesh->SetRelativeScale3D(FVector((cSize / 10.f), (cSize / 10.f), (cSize / 10.f)));

	cPosition = GetActorLocation();
	//set position (last position should be same in this moment)
	cLastPosition = cPosition;

	//StateMachine setup and register
	//do it in new function as it'll be inherited by others
	stateRegister();


}

void ACreature::initialize(float inSpeed, float inSize, int inPower, int inDef, int inHP, float inSight)
{
	//random generate the parameters with +-20% (except sight is 60-100%)
	cSpeed = FMath::RandRange((inSpeed*8/10), (inSpeed * 12 / 10));
	cSize = FMath::RandRange((inSize * 8.f / 10.f), (inSize * 12.f / 10.f));
	cPower = FMath::RandRange((inPower * 8 / 10), (inPower * 12 / 10));
	cDef = FMath::RandRange((inDef * 8 / 10), (inDef * 12 / 10));
	cHP = FMath::RandRange((inHP * 8 / 10), (inHP * 12 / 10));
	cSight = FMath::RandRange((inSight * 8.f / 10.f), (inSight));

	//set its scaling
	float scaleMulti = (cSize / inSize) ;
	Mesh->SetRelativeScale3D(FVector(scaleMulti, scaleMulti, scaleMulti));

	cPosition = GetActorLocation();
	//set position (last position should be same in this moment)
	cLastPosition = cPosition;

	//StateMachine setup and register
	//do it in new function as it'll be inherited by others
	stateRegister();





}

// Called when the game starts or when spawned
void ACreature::BeginPlay()
{
	Super::BeginPlay();
	
	setPathfinder();
	//initialize the parameeter
	initialize();

	cType = CREATURE;
	//set default state
	m_StateMachine->ChangeState(STATE_WANDER);
}

void ACreature::setPathfinder()
{
	//get the path finding actor
	for (TActorIterator<APathfind> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
		cPathfinder = *ActorItr;
	}

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

	if (cType == CREATURE) {
	//do the state machine tick operations
	m_StateMachine->Tick(DeltaTime);
	}


}

// Called to bind functionality to input
void ACreature::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACreature::TakeDmg(int inAtk)
{
	//damage calculation: attack from others-defence
	int finalDmg = inAtk - cDef;
	//if defence is more than attack, keep it at 1 as well
	if (finalDmg <= 0) {
		finalDmg = 1;
	}
	//and then take damage to the HP
	cHP -= finalDmg;
	//if HP is less than 0, change state to die.
	if (cHP <= 0) {
		m_StateMachine->ChangeState(STATE_DIE);//<--problem
	}
	else {
		m_StateMachine->ChangeState(STATE_HIT);//<--problem
	}
}

FVector ACreature::genRandomLocation(FVector initPos, float inRange, bool isNeedValidCheck, float inCheckRange)
{
	FVector outVector=FVector::ZeroVector;
	FRandomStream randomVal;
	randomVal.GenerateNewSeed();
	//outVector.X = initPos.X + randomVal.FRandRange(0.f,(inRange * 2)) - inRange;
	outVector.X = initPos.X + FMath::FRandRange((inRange*-1.f), inRange);
	randomVal.GenerateNewSeed();
	outVector.Y = initPos.Y + FMath::FRandRange((inRange*-1.f), inRange);
	//outVector.Y = initPos.Y + randomVal.FRandRange(0.f,(inRange * 2)) - inRange;
	outVector.Z = 0.f;

	//check if the location is valid, if not do it until it's valid<--maybe in a new function?
	//condition to do: the valid check switch is label as true
	if (isNeedValidCheck) {
		while (!checkPosValid(outVector, inCheckRange)) {
			randomVal.GenerateNewSeed();
			//outVector.X = initPos.X + randomVal.FRandRange(0.f,(inRange * 2)) - inRange;
			outVector.X = initPos.X + FMath::FRandRange((inRange*-1.f), inRange);
			randomVal.GenerateNewSeed();
			outVector.Y = initPos.Y + FMath::FRandRange((inRange*-1.f), inRange);
			//outVector.Y = initPos.Y + randomVal.FRandRange(0.f,(inRange * 2)) - inRange;
			outVector.Z = 0.f;
		}
	}
	return outVector;
}

void ACreature::move(float DeltaTime, bool isDash)
{

	float finalSpeed = cSpeed / (cSize/10.f) * 1000.f;
	//if it's dashing, the speed will be twiced
	if (isDash) {
		finalSpeed *= 2.f;
	}

	//set the location
		//if there's has the route, run by each node
	SetActorLocation(FMath::VInterpConstantTo(cPosition, cTargetPosition, DeltaTime, finalSpeed));
	
	//set the rotation
	FRotator finalRot = cVelocity.Rotation();
	finalRot.Yaw += 90.f;
	SetActorRotation(finalRot);

}

bool ACreature::checkPosValid(FVector checkPos, float sweepArea)
{

	//array of“FHitResult”that is going to store all the objects our hit detection registers
	TArray<FHitResult>OutHits;
	//get our locationandcreate a sphere collider.
	FVector location = checkPos;
	FCollisionShape CheckSphere = FCollisionShape::MakeSphere(sweepArea);

	//make sure it's inside -4000 to 4000 range.
	if ((abs(checkPos.X) / (4000.f-cSize)) >= 1.f ||(abs(checkPos.Y)/(4000.f-cSize))>=1.f) {
		return false;
	}

	//sweep the position according to the sweeping area
	//perform a“SweepMultiByChannel”which creates a shape based onthe last parameter, located at the position in the 2nd/3rd parameter.2nd/3rd parameter are the start and end points of a“Sweep”of the shape.
	//Any objects that overlap are then stored in the first parameter(our TArray)
	bool isHit = GetWorld()->SweepMultiByChannel(OutHits, location, location, FQuat::Identity, ECC_WorldStatic, CheckSphere);

	if (isHit) {
		//loop throughall our objects(autocasting them),get their mesh component and then if that was successful, apply a force to that object. 
		//The force has a start, size, amount, falloff and a boolean checking if to NOT use mass.
		for (auto& Hit : OutHits) {
			//if it has a wall, or a creature, or a food pallet, return false
			AWall* wall = Cast<AWall>((Hit.GetActor()));
			if (wall) {
				return false;
			}
			ACreature* creature = Cast<ACreature>((Hit.GetActor()));
			if (creature) {
				return false;
			}
		}
	}
	else {
		return true;

	}
	return true;
}

TArray<FHitResult> ACreature::getSurroundings()
{
	//array of“FHitResult”that is going to store all the objects our hit detection registers
	TArray<FHitResult>OutHits;
	//get our locationandcreate a sphere collider.
	FCollisionShape CheckSphere = FCollisionShape::MakeSphere(cSight);

	//sweep the position according to the sweeping area
	//perform a“SweepMultiByChannel”which creates a shape based onthe last parameter, located at the position in the 2nd/3rd parameter.2nd/3rd parameter are the start and end points of a“Sweep”of the shape.
	//Any objects that overlap are then stored in the first parameter(our TArray)
	bool isHit = GetWorld()->SweepMultiByChannel(OutHits, cPosition, cPosition, FQuat::Identity, ECC_WorldStatic, CheckSphere);
	
	//if there's result, return the array of results
	if (isHit) {
		return OutHits;
	}
	//otherwise just output an array with no data
	else {
		OutHits.Empty();
		return OutHits;
	}
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
	//generate a path of the target
	cPathlist = cPathfinder->GeneratePath(cPosition, genRandomLocation(FVector::ZeroVector, 2000.f, true, cSize));
	//set target location to the first index of the path list
	//cTargetPosition = genRandomLocation(FVector::ZeroVector, 2000.f,true,cSize);
	cPathlistID = cPathlist.Num() - 1;
	cTargetPosition = cPathlist[cPathlistID];
}
void ACreature::State_Wander_OnTick(float f_DeltaTime) {
	//if creature arrive nearby the location, change another random location
	//maybe also if the path array length is not zero, and the index is the last node, will be find a new path
	FVector vectorToTarget = cTargetPosition - cPosition;

	if (FVector::Distance(cTargetPosition, cPosition) < (cSize*2)) {
		//change to another index when not finished its path.
		//change another target when reached
		if (cTargetPosition == cPathlist[0] || cPathlistID == 0) {
			//cTargetPosition = genRandomLocation(FVector::ZeroVector, 2000.f, true, cSize);
			cPathlist = cPathfinder->GeneratePath(cPosition, genRandomLocation(FVector::ZeroVector, 4000.f, true, cSize * 2));
			while (cPathlist.Num() <= 0) {
				//i don't want a path that is 0, although the path must be more than 1, but just in case.
				cPathlist = cPathfinder->GeneratePath(cPosition, genRandomLocation(FVector::ZeroVector, 4000.f, true, cSize * 2));
			}
			cPathlistID = cPathlist.Num() - 1;
			cTargetPosition = cPathlist[cPathlistID];
		}
		else {
			cPathlistID -= 1;
			cTargetPosition = cPathlist[cPathlistID];
		}
	}

	//and let the actor move
	move(f_DeltaTime, false);

	//other creature will do it based on this function.
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
	else {
		//otherwise get back to wandering mode.
		m_StateMachine->ChangeState(cLastState);
	}

}
void ACreature::State_Flee_OnExit(void) { SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Spawn_OnEnter(void) {}
void ACreature::State_Spawn_OnTick(float f_DeltaTime) {
	//generate a new same creature with a slightly different status based on parent status.
	//do it after different creature types created.
	//debug msg for spawned.
}
void ACreature::State_Spawn_OnExit(void) { SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Die_OnEnter(void) {}
void ACreature::State_Die_OnTick(float f_DeltaTime) {
	Destroy();
	//debug msg for destoryed
}
void ACreature::State_Die_OnExit(void) { }

void ACreature::State_Hit_OnEnter(void) {
	//set the lag time be 3s
	cTime = 1.f;
	//reset the timer
	cTimer = 0.f;
}
void ACreature::State_Hit_OnTick(float f_DeltaTime) {
	//if time's up, change the status back to normal(might be overloaded when needed.
	if (cTimer >= cTime) {
		if (cLastState != STATE_HIT) {
			m_StateMachine->ChangeState(cLastState);
		}
		else {
			m_StateMachine->ChangeState(STATE_WANDER);
		}
	}
	else {
		cTimer += f_DeltaTime;
	}
}
void ACreature::State_Hit_OnExit(void) { SetLastState(m_StateMachine->GetCurrentState()); }

void ACreature::State_Standby_OnEnter(void) {}
void ACreature::State_Standby_OnTick(float f_DeltaTime) {}//this function is mainly used for hider for keep staying it in place and do some operation in some cond.
void ACreature::State_Standby_OnExit(void) { SetLastState(m_StateMachine->GetCurrentState()); }
