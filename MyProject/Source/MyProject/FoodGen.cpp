// Fill out your copyright notice in the Description page of Project Settings.

#include "FoodGen.h"
#include "Creature.h"
#include "Wall.h"
#include <EngineGlobals.h>
#include "Engine/GameEngine.h"


// Sets default values
AFoodGen::AFoodGen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFoodGen::BeginPlay()
{
	Super::BeginPlay();
	randomTime = defaultTime + FMath::FRandRange(0, (defaultTime*0.1f));
	genTimer = 0;
}

void AFoodGen::genFood()
{
}

FVector AFoodGen::genRandomLocation(FVector initPos, float inRange, bool isNeedValidCheck, float inCheckRange)
{
	FVector outVector = FVector::ZeroVector;
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

bool AFoodGen::checkPosValid(FVector checkPos, float sweepArea)
{
	//array of“FHitResult”that is going to store all the objects our hit detection registers
	TArray<FHitResult>OutHits;
	//get our locationandcreate a sphere collider.
	FVector location = checkPos;
	FCollisionShape CheckSphere = FCollisionShape::MakeSphere(sweepArea);

	//make sure it's inside -2000 to 2000 range.
	if ((abs(checkPos.X) / (2000.f - sweepArea)) >= 1.f || (abs(checkPos.Y) / (2000.f - sweepArea)) >= 1.f) {
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

// Called every frame
void AFoodGen::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);
	if (genTimer > randomTime) {
		genFood();
		//reset the timer and new random time
		randomTime = defaultTime + FMath::FRandRange(0.f, (defaultTime*0.1f));
		genTimer = 0.f;
	}
	else {
		genTimer += DeltaTime;
	}

}

