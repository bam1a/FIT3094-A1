// Fill out your copyright notice in the Description page of Project Settings.

#include "Wall.h"

// Sets default values
AWall::AWall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//we want our RootComponent to be the mesh(We will be applying physics to it)
	RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	//andset our Mesh property to reference the RootComponent
	Mesh = Cast<UStaticMeshComponent>(RootComponent);
	Mesh->SetSimulatePhysics(false);
}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

