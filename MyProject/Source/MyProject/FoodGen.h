// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Food.h"
#include "FoodGen.generated.h"

UCLASS()
class MYPROJECT_API AFoodGen : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodGen();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float genTimer;
	UPROPERTY(EditAnywhere)
		float defaultTime=30.f;
	UPROPERTY(VisibleAnywhere)
		float randomTime = 0.f;
	void genFood();
	FVector genRandomLocation(FVector initPos, float inRange, bool isNeedValidCheck = false, float inCheckRange = 1.f);
	bool checkPosValid(FVector checkPos, float sweepArea);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
