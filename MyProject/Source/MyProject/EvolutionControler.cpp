// Fill out your copyright notice in the Description page of Project Settings.

#include "EvolutionControler.h"
#include "FileHelper.h"
#include "Hunter.h"
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "Paths.h"


// Sets default values
AEvolutionControler::AEvolutionControler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AEvolutionControler::~AEvolutionControler()
{
}

// Called when the game starts or when spawned
void AEvolutionControler::BeginPlay()
{
	Super::BeginPlay();
	//delete all pointers
	delete NNetwork;
	NNetwork = nullptr;
	//load neuro network from game content file and set the weight up.
	loadNetwork(); 
	//load genomes
	
	//temp. placement: saving the network
	saveNetwork();

}

// Called every frame
void AEvolutionControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEvolutionControler::setGenomeCouple(ACreature * inCreature, float inTimeFitness, int inKillFitness)
{
	//	Genome(float inSpeed, float inSize, float inSight, int inPower, int inDef, int inHP, FVector inPos, float inTimeFitness, int inKillFitness) {
	breedCouples.Add(new Genome(inCreature->GetSpeed(), 
		inCreature->GetSize(), 
		inCreature->GetSight(),
		inCreature->GetPower(),
		inCreature->GetDef(),
		inCreature->GetHP(),
		inCreature->GetPos(),inTimeFitness,inKillFitness));
}

double AEvolutionControler::NeuronDecision(TArray<double>& inputValue)
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

void AEvolutionControler::saveNetwork()
{
	//initialize, and make some buffers when writing file
		//can't use "\n"to make a new line, only using array could solve it.
	TArray<FString> textStringArr;
	//textStringArr.Push(TEXT("testing\n123\t456 78"));
	//textStringArr.Push(TEXT("africa is the best"));
	//temp. string
	FString lineString="";
	FString fileLoc = FPaths::ProjectContentDir() + "AAAAA.txt";
	//adding topology
	lineString = "topology:";
	for (int i : NNetwork->getTopology()) {
		lineString.Append(" ");
		lineString.Append(FString::FromInt(i));
	}
	textStringArr.Push(lineString);
	//adding neuron structures
		//get the neuron output weight structure(except the last layer as it has no meaning of weights.
	TArray<TArray<TArray<double>>> neuroOutputWeight = NNetwork->getNeuroOutputWeight();
	for (int i = 0; i < neuroOutputWeight.Num() - 1; i++) {
		lineString = TEXT("L" + FString::FromInt(i+1)+":");
		for (TArray<double>iNeuro : neuroOutputWeight[i]) {
			lineString.Append(TEXT("	"));
			for (double iWeight : iNeuro) {
				lineString.Append(FString::SanitizeFloat(iWeight));
				lineString.Append(" ");
			}
			//remove the last space char to maintain the format.
			lineString.RemoveAt(lineString.Len() - 1,1);
		}
		textStringArr.Push(lineString);
	}
	//overwrite the whole file.
	FFileHelper::SaveStringArrayToFile(textStringArr, *fileLoc);
	TArray<FString> fileStringArr;
	FFileHelper::LoadANSITextFileToStrings(*fileLoc, NULL, fileStringArr);

}

void AEvolutionControler::loadNetwork()
{	
	//initialize, and make some buffers when reading file
	FString fileString, fLine;
	TArray<FString> fileStringArr;
	FString fileLoc = FPaths::GameContentDir() + "HunterDNA.txt";
	FFileHelper::LoadANSITextFileToStrings(*fileLoc, NULL, fileStringArr);

	TArray<unsigned> inTopo;//line 0 of file=topology
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
	NNetwork = new Network(inTopo); 
	NNetwork->overwriteNeurons(inNeuro);

	//remaining: genomes
		//to be done


}

