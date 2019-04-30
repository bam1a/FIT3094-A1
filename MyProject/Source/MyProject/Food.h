// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PathNode.h"
#include "Food.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AFood : public APathNode
{
	GENERATED_BODY()
public:
	AFood();
	void BeEaten();
};
