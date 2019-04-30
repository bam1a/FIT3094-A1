// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PathNode.h"
#include "Shelter.generated.h"

/**
 * shelter will do the same thing as the path node, but will be detected by
 */
UCLASS()
class MYPROJECT_API AShelter : public APathNode
{
	GENERATED_BODY()
public:
	AShelter();
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere)
	float shelterArea;

};
