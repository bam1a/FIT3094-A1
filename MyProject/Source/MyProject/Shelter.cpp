// Fill out your copyright notice in the Description page of Project Settings.

#include "Shelter.h"
#include "ConstructorHelpers.h"
#include <EngineGlobals.h>
#include "Engine/GameEngine.h"


AShelter::AShelter() :APathNode() {
	nNodeType = SHELTER;


}

void AShelter::BeginPlay()
{
	Super::BeginPlay();
	nNodeType = SHELTER;

}
