// Fill out your copyright notice in the Description page of Project Settings.


#include "generator.h"
#include "Wall.h"
#include "Food.h"
#include "Creature.h"
#include "Gatherer.h"
#include "Hider.h"
#include "Hunter.h"
#include "ConstructorHelpers.h"
#include "DrawDebugHelpers.h"
#include "Engine/GameEngine.h"

// Sets default values
Agenerator::Agenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnedArray.Empty();
}

// Called when the game starts or when spawned
void Agenerator::BeginPlay()
{
	Super::BeginPlay();
	resetTimer();
	//setup a location Vector
	FVector newLocation;
	float cSize = 4000.f;
	//generate couple of food pallet based on the config.
	for (int i = 0; i < foodGenCount; i++) {
		newLocation = genRandomLocation(FVector::ZeroVector, 4000.f, true, 100.f);
		spawnActortoWorld<AFood>(newLocation);
	}
	//generate Gatherer,Hider,Hunter based on the config.
	for (int i = 0; i < GathererCount; i++) {
		generateGatherer(FVector::ZeroVector, 4000.f, 100.f);
	}
	for (int i = 0; i <HiderCount; i++) {
		generateHider(FVector::ZeroVector, 4000.f, 100.f);
	}
	//for (int i = 0; i < HunterCount; i++) {
	//	newLocation = genRandomLocation(FVector::ZeroVector, 4000.f, true, 100.f);
	//	spawnActortoWorld<AHunter>(newLocation);
	//}
}

void Agenerator::resetTimer()
{
	genTime = FMath::RandRange(30.f, 40.f);
	genTimer = 0.f;
}

// Called every frame
void Agenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//when time's up, generate a new food pallet
	if (genTimer >= genTime) {
		for (int i = 0; i < 10; i++) {
			FVector newLocation = genRandomLocation(FVector::ZeroVector, 4000.f, true, 100.f);
			spawnActortoWorld<AFood>(newLocation);
		}
		//and reset the timer
		resetTimer();
	}
	else {
		genTimer += DeltaTime;
	}
	//if out of hider/ gatherer, regenerate them
	if (spawnedGatherers.Num() <= 0) { 
		for (int i = 0; i < GathererCount; i++) {
			 generateGatherer(FVector::ZeroVector, 4000.f, 100.f);
		}
	}
	if (spawnedHiders.Num() <= 0) {
		for (int i = 0; i < HiderCount; i++) {
			generateHider(FVector::ZeroVector, 4000.f, 100.f);
		}
	}

}


void Agenerator::generateHider( FVector inLoc, float inSize, float inCheckRange)
{
	FVector newLocation = genRandomLocation(inLoc, inSize, true, inCheckRange);

	//generate Gatherer,Hider,Hunter based on the config.
	AActor* newActor=spawnActortoWorld<AHider>(newLocation);
	spawnedHiders.Add(newActor);

}

void Agenerator::generateGatherer(FVector inLoc, float inSize, float inCheckRange)
{
	FVector newLocation = genRandomLocation(inLoc, inSize, true, inCheckRange);

	//generate Gatherer,Hider,Hunter based on the default config.
	AActor* newActor = spawnActortoWorld<AGatherer>(newLocation);
	spawnedGatherers.Add(newActor);

}



FVector Agenerator::genRandomLocation(FVector initPos, float inRange, bool isNeedValidCheck, float inCheckRange)
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

bool Agenerator::checkPosValid(FVector checkPos, float sweepArea)
{
	//array of“FHitResult”that is going to store all the objects our hit detection registers
	TArray<FHitResult>OutHits;
	//get our locationandcreate a sphere collider.
	FVector location = checkPos;
	FCollisionShape CheckSphere = FCollisionShape::MakeSphere(sweepArea);

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

