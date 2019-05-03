// Fill out your copyright notice in the Description page of Project Settings.

#include "Food.h"
#include "ConstructorHelpers.h"
#include <EngineGlobals.h>
#include "Engine/GameEngine.h"



AFood::AFood():APathNode() {
	nNodeType = FOOD;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		Mesh->SetStaticMesh(SphereVisualAsset.Object);
	}
	//Get Material
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/assignmentContent/Material.Material"));
	if (FoundMaterial.Succeeded())
	{
		DynamicMaterialInst = UMaterialInstanceDynamic::Create((UMaterial*)FoundMaterial.Object, Mesh);
		DynamicMaterialInst->SetVectorParameterValue(FName(TEXT("Colour")), FLinearColor(1.0, 1.0, 0.0, 1.0));
		Mesh->SetMaterial(0, DynamicMaterialInst);
	}


}

void AFood::BeginPlay()
{
	Super::BeginPlay();
	nNodeType = FOOD;
}

void AFood::BeEaten()
{
	Destroy();
}
