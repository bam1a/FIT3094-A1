// Fill out your copyright notice in the Description page of Project Settings.

#include "EvolutionControler.h"
#include "FileHelper.h"
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "Paths.h"


// Sets default values
AEvolutionControler::AEvolutionControler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEvolutionControler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEvolutionControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

double AEvolutionControler::NeuronDecision(TArray<double> inputValue)
{
	//inputValue: a array of input value with the following format:
		//0:prayNum, 1:hunterNum, 2:killCount, 3:spawnCount
	//feed the neuron network by these input value
	NNetwork->feedForward(inputValue);
	//and then get the result
	TArray<double>resultValues;
	NNetwork->getResult(resultValues);
	//as it has only 1 value existed, so only the index 0 of the resultValues will be output.
	return resultValues[0];
}

void AEvolutionControler::adjustDecision(double actualOutput)
{
	//back propergate the actual output to the neuron network
	//but first wrap it into an array
	TArray<double> actualOutputArr;
	actualOutputArr.Push(actualOutput);
	NNetwork->backPropagation(actualOutputArr);
}

void AEvolutionControler::loadNetwork()
{	
	//initialize, and make some buffers when reading file
	FString fileString, fLine;
	TArray<FString> fileStringArr;
	FString fileLoc = FPaths::GameContentDir() + "HunterDNA.txt";
	FFileHelper::LoadANSITextFileToStrings(*fileLoc, NULL, fileStringArr);

	TArray<int> inTopo;//line 0 of file=topology
	//TArray<TArray<double>> inNeuro;//remaining lines: saved neurons based on the topology.
	TArray<TArray<TArray<double>>> inNeuro;
	inTopo.Empty();
	inNeuro.Empty();

	//make the data arrays from the raw string
	TArray<FString> tempStringArr;
	//line0=topology
	fileStringArr[0].ParseIntoArray(tempStringArr, TEXT(" "));
	for (int i = 1; i < tempStringArr.Num(); i++) {
		inTopo.Push(FCString::Atoi(*tempStringArr[i]));
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(inTopo.Top()));
	}
	//line 1-(topology layers-1) : based on the topology layers=neuron values
	//template:    L0:	0.0 0.0 0.0		0.0 0.0 0.0		0.0 0.0 0.0
	TArray<TArray<double>>dummyLineArr;
	TArray<double>dummyNeuronArr;
	//load from line 1 to the last layer of topology(1+inTopo.Num-1)
	for (int j = 1; j < inTopo.Num(); j++) {
		//reset the string array buffer
		tempStringArr.Empty();
		//get the neuron weights based on the tabs
		fileStringArr[j].ParseIntoArray(tempStringArr, TEXT("	"));
		//create a dummy array of layer for adding a new layer of weights
		inNeuro.Push(dummyLineArr);
		//loop every neuron in this layer
		for (int i = 1; i < tempStringArr.Num(); i++) {
			TArray<FString> tempNeuroStringArr;
			//get the neuron output weight based on the spaces
			tempStringArr[i].ParseIntoArray(tempNeuroStringArr, TEXT(" "));
			//create a dummy array of neuron weights for adding a new weights
			inNeuro.Top().Push(dummyNeuronArr);
			for (FString iWeight : tempNeuroStringArr) {
				//set it to the neuro data container inNeuro
				inNeuro.Top().Top().Push(FCString::Atod(*iWeight));
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::SanitizeFloat(inInput.Top().Top()));
			}
		}
	}

	// set current neuron output weight to the network.

	//remaining: genomes
	//to be done


}
