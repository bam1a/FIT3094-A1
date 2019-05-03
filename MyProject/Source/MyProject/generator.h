// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "generator.generated.h"

UCLASS()
class MYPROJECT_API Agenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Agenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//variables
	//genTime: the time for spawning food
	//genTimer: the time incementer for detemine spawn food or not
	UPROPERTY(VisibleAnywhere, Category = "InitialGeneratingSettings")
	float genTime;
	UPROPERTY(VisibleAnywhere, Category = "InitialGeneratingSettings")
	float genTimer;

	void resetTimer();
	
	UPROPERTY(EditAnywhere, Category = "InitialGeneratingSettings")
		int HunterCount;
	UPROPERTY(EditAnywhere, Category = "InitialGeneratingSettings")
		int GathererCount;
	UPROPERTY(EditAnywhere, Category = "InitialGeneratingSettings")
		int HiderCount;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//containers for each generated food pallets and creatures.
	TArray<AActor*> SpawnedArray;
	//containers for each generated creatures
	TArray<AActor*> spawnedCreature;


	//T- the actor class which requested for spawn
	//function to generate an object based on the position or generate itself by default
	template<class T>
	void spawnActortoWorld(FVector inPosition);

	FVector genRandomLocation(FVector initPos, float inRange, bool isNeedValidCheck = false, float inCheckRange = 1.f);
	bool checkPosValid(FVector checkPos, float sweepArea);


};



template<class T>
inline void Agenerator::spawnActortoWorld(FVector inPosition) {
	T* newActor = GetWorld()->SpawnActor<T>(T::StaticClass(), inPosition, FRotator::ZeroRotator);
	SpawnedArray.Add(Cast<AActor>(newActor));
}
