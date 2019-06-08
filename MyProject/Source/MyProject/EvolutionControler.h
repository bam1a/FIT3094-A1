// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Network.h"
#include "Creature.h"
#include "generator.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "EvolutionControler.generated.h"

struct Genome {
	//genome format:
	//speed, size, sight, power, def, HP, fitness(if needed)
	float speed, size,sight,fitness;
	int power, def, HP;
	FVector pos;
	Genome(float inSpeed, float inSize, float inSight, int inPower, int inDef, int inHP, FVector inPos, float inTimeFitness, int inKillFitness) {
		speed = inSpeed;
		size = inSize;
		sight = inSight;
		power = inPower;
		def = inDef;
		HP = inHP;
		fitness = inTimeFitness + (inKillFitness * 10.f);
	}
	//comparison function?
};

UCLASS()
class MYPROJECT_API AEvolutionControler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEvolutionControler();
	~AEvolutionControler();
	Network* NNetwork;

	FString ServingType = "Hunter";

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//genetic evolution related
	TArray<Genome*> breedCouples;
	Genome* bestGenome = nullptr;
	Genome* bestGenome2 = nullptr;
	TArray<Genome*> genomeList;

	//used to generate a new creature
	UPROPERTY(EditAnywhere, Category = "InitialGeneratingSettings")
		Agenerator* generator;

	//used to generate some default hunters when startup?
	UPROPERTY(EditAnywhere, Category = "InitialGeneratingSettings")
		int SpawnCount;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*
genetic algo.
	//breeding(make 1 seed to swap?)
	//mutate(use 1 variations to alter)
	//generate new 3 set of creatures based on the couples
	//load and save genomes.
*/
	void setGenomeCouple(ACreature* inCreature, float inTimeFitness, int inKillFitness);
	void breed(int seedCount);
	void mutate(int seedCount);
	void generateByGenomes();
	void loadGenome();
	void saveGenome();

	double NeuronDecision(TArray<double>&inputValue);
	void adjustDecision(double actualOutput);

	void saveNetwork();
	void loadNetwork();

};
