// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Network.h"
#include "Hunter.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "EvolutionControler.generated.h"

struct Genomes {
	float speed, size,sight;
	int power, def, HP;
};

UCLASS()
class MYPROJECT_API AEvolutionControler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEvolutionControler();
	Network* NNetwork;
//	TArray<AHunter> breedCouples;
//	TArray<Genomes> genomeList;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*
genetic algo.
	//breeding(make 3 seeds to swap?)
	//mutate(use 3 variations to alter)
	//generate new set of creatures.
*/
	void breed();
	void mutate();
	void generateByGenomes();

	double NeuronDecision(TArray<double>inputValue);
	void adjustDecision(double actualOutput);

	void saveNetwork();
	void loadNetwork();
	void loadGenome();

};
