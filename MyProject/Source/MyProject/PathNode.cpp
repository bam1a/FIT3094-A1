// Fill out your copyright notice in the Description page of Project Settings.

#include "PathNode.h"
#include "Pathfind.h"

// Sets default values
APathNode::APathNode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//we want our RootComponent to be the mesh(We will be applying physics to it)
	RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	//andset our Mesh property to reference the RootComponent
	Mesh = Cast<UStaticMeshComponent>(RootComponent);
	UMaterialInstanceDynamic* DynamicMaterialInst=nullptr;

	nPosition = GetActorLocation();
	nNodeType = PATH;

	//APathNode::NodeList.Push(this);
	//APathfind::NodeArray.Add(this);
}

// Called when the game starts or when spawned
void APathNode::BeginPlay()
{
	Super::BeginPlay();
	nPosition = GetActorLocation();
}



FString APathNode::getNodeType()
{
	FString outString = "";
	if (nNodeType == PATH) {
		return "Path";
	}
	else if (nNodeType == FOOD) {
		return "Food";
	}
	else if (nNodeType == SHELTER) {
		return "Shelter";
	}
	return "";
}

// Called every frame
void APathNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}
//TArray<APathNode*> APathNode::NodeList;

