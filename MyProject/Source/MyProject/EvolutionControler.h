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
	Genome(float inSpeed, float inSize, float inSight, int inPower, int inDef, int inHP, FVector inPos) {
		speed = inSpeed;
		size = inSize;
		sight = inSight;
		power = inPower;
		def = inDef;
		HP = inHP;
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
	Network* NNetwork;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	TArray<Genome*> breedCouples;
	TArray<Genome*> genomeList;

	UPROPERTY(EditAnywhere, Category = "InitialGeneratingSettings")
		Agenerator* generator;

	UPROPERTY(EditAnywhere, Category = "InitialGeneratingSettings")
		int HunterCount;

	double timer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*
genetic algo.
	//breeding(make 3 seeds to swap?)
	//mutate(use 3 variations to alter)
	//generate new set of creatures.
*/
	void setGenomeCouple(ACreature* inCreature);
	void breed();
	void mutate();
	void generateByGenomes();
	void loadGenome();

	double NeuronDecision(TArray<double>inputValue);
	void adjustDecision(double actualOutput);

	void saveNetwork();
	void loadNetwork();

};
