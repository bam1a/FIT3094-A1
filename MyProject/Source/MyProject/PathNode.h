// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PathNode.generated.h"

UCLASS()
class MYPROJECT_API APathNode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APathNode();

	static enum Node_Type {
		PATH=0,
		WATER,
		SHELTER,
		FOOD
	};

	static TArray<APathNode*> NodeList;

protected:
	//the bounding box mesh(if have)
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UMaterialInstanceDynamic* DynamicMaterialInst;

	
	//position of the node
	FVector nPosition;

	//connected path of the node(can be keep cognito if no neighbour.)
	UPROPERTY(EditAnywhere, Category = NodeSettings)
	TArray<APathNode*> neighbourNode;
	
	//valid radius of the node,set it in editor?
	//UENUM(BlueprintType)
	//UPROPERTY(EditAnywhere, Category = NodeSettings)
	Node_Type nNodeType;

	//reaching radius of the node<--no need?
	//UPROPERTY(EditAnywhere, Category = NodeSettings)
		//float nReachDistance;

	
public:	
	//assessor
	//getPosition: return a position
	FVector GetPosition() { return nPosition; };
	//getNeighbourNode: return neighbour nodes(in pointer form)
	TArray<APathNode*>* GetNeighbourNode() { return &neighbourNode; };
	//getNodeType: return the type of the node
	FString getNodeType();

	//mutator----read only, doesn't need?

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
