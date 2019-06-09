// Fill out your copyright notice in the Description page of Project Settings.

#include "EvolutionControler.h"
#include "FileHelper.h"
#include "Hunter.h"
#include <algorithm>
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
	loadGenome();

	//generate hunters to the generator.(via tick)

}

// Called every frame
void AEvolutionControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (breedCouples.Num() >= 2) {
		//do the breed process
		breed(1);
		//and then mutate
		mutate();
		//and then generate it to the map using the index 0 of the couple's position
		generateByGenomes(spawnPos,spawnSize,spawnSize);
		//and then clear those couple pointers
		for (int i = 0; i < breedCouples.Num(); i++) {
			breedCouples.Pop();
		}
	}
	//if all hunters are died, regen the hunters
	if (generator->spawnedHunters.Num() <= 0) {
		regenGenome();
	}
	if (time >= 1.f) {
		saveSettings();
		time = 0.f;
	}
	time += DeltaTime;
}

void AEvolutionControler::setGenomeCouple(ACreature * inCreature, float inTimeFitness, int inKillFitness)
{
	//set a new genome based on this creature.
	//	Genome(float inSpeed, float inSize, float inSight, int inPower, int inDef, int inHP, FVector inPos, float inTimeFitness, int inKillFitness) {
	breedCouples.Add(new Genome(inCreature->GetSpeed(), 
		inCreature->GetSize(), 
		inCreature->GetSight(),
		inCreature->GetPower(),
		inCreature->GetDef(),
		inCreature->GetHP(),
		inTimeFitness,inKillFitness));
	//set couple position
	spawnPos = inCreature->GetPos();
	spawnSize = inCreature->GetSize();
	//check the fitness is the best or not
	//if that genome is better than the best 2, then set it to the array. and toss the worse 1.
	bestGenome.Add(breedCouples.Top());
	Algo::Sort(bestGenome, [](Genome* LHS, Genome* RHS) { return LHS->fitness> RHS->fitness; });
	Genome* worstGenome =bestGenome.Pop();
	delete worstGenome;
	worstGenome = nullptr;

}

void AEvolutionControler::breed(int seedCount)
{
	//loop the breed process depends on the seed count
	for (int i = 0; i < seedCount; i++) {
		//make an array of true/false that determines which index should be swap.
		//6 parameters can be add
		TArray<bool> swapSeed;
		for (int j = 0; j < 6; j++) {
			swapSeed.Add(FMath::RandBool());
		}
		//then the 1st genome cross the 2-nth genomes
		for (int j = 1; j < breedCouples.Num(); j++) {
			genomeList+=cross(breedCouples[0], breedCouples[1],swapSeed);
		}
		//breed with another random genome?<-- maybe nope.
	}
}

TArray<Genome*> AEvolutionControler::cross(Genome * genome1, Genome * genome2, TArray<bool>&swapSeed)
{
	Genome* tempGene1 = new Genome(*genome1);
	Genome* tempGene2 = new Genome(*genome2);
	TArray<Genome*>tempGenomeArr;
	//speed
	if (swapSeed[0]) {
		swap(tempGene2->speed,tempGene1->speed);
	}
	//size
	if (swapSeed[1]) {
		swap(tempGene2->size, tempGene1->size);
	}
	//sight
	if (swapSeed[2]) {
		swap(tempGene2->sight, tempGene1->sight);
	}
	//power
	if (swapSeed[3]) {
		swap(tempGene2->power, tempGene1->power);
	}
	//def
	if (swapSeed[4]) {
		swap(tempGene2->def, tempGene1->def);
	}
	//hp
	if (swapSeed[5]) {
		swap(tempGene2->HP, tempGene1->HP);
	}
	tempGenomeArr.Add(tempGene1);
	tempGenomeArr.Add(tempGene2);

	return tempGenomeArr;
}

void AEvolutionControler::mutate()
{
	//expect all of it must be mutated
		//make an array of true/false that determines which index should be swap.
		//6 parameters can be add
		TArray<bool> swapSeed;
		for (int j = 0; j < 6; j++) {
			swapSeed.Add(FMath::RandBool());
		}
		//mutate seed 20%(hardcoded)
		float alterPercent = 0.2;
		for (Genome* iGenome : genomeList) {
			//speed
			if (swapSeed[0]) {
				iGenome->speed *= FMath::FRandRange((1 - alterPercent), (1 + alterPercent));
			}
			//size
			if (swapSeed[1]) {
				iGenome->size *= FMath::FRandRange((1 - alterPercent), (1 + alterPercent));
			}
			//sight
			if (swapSeed[2]) {
				iGenome->sight *= FMath::FRandRange((1 - alterPercent), (1 + alterPercent));
			}
			//power
			if (swapSeed[3]) {
				iGenome->power *= FMath::FRandRange((1 - alterPercent), (1 + alterPercent));
			}
			//def
			if (swapSeed[4]) {
				iGenome->def *= FMath::FRandRange((1 - alterPercent), (1 + alterPercent));
			}
			//hp
			if (swapSeed[5]) {
				iGenome->HP *= FMath::FRandRange((1 - alterPercent), (1 + alterPercent));
			}

		}
	
}

void AEvolutionControler::generateByGenomes(FVector inPos, float inSize, float inCheckRange)
{
	//loop all the genome from the genome List and turn it into a creature.
	for (Genome* iGenome : genomeList) {
		FVector newLocation = generator->genRandomLocation(inPos, inSize*2, true, inCheckRange);
		//generate Hunter based on the config in the genome
		AActor* newActor = generator->spawnActortoWorld<AHunter>(newLocation);
		Cast<AHunter>(newActor)->overridePara(iGenome->speed, iGenome->size, iGenome->power, iGenome->def, iGenome->HP, iGenome->sight);
		generator->spawnedHunters.Add(newActor);
	}
	//clear the genome list after finish the loop
	for (Genome* i : genomeList) {
		delete i;
	}
	genomeList.Empty();
}

void AEvolutionControler::regenGenome()
{
	//reset the best genomes
	breedCouples.Empty();
	//set the best genome as the couple
	for (Genome* iGenome : bestGenome) {
		breedCouples.Add(iGenome);
	}
	//breed and mutate with 3 seeds(6 genomes generated)
	breed(3);
	mutate();
	//and then generate it to the map
	spawnPos = FVector::ZeroVector;
	spawnSize = 2000.f;
	generateByGenomes(spawnPos,spawnSize,100.f);

	breedCouples.Empty();
}

void AEvolutionControler::loadGenome()
{
	//initialize, and make some buffers when reading file
	FString fileString, fLine;
	TArray<FString> fileStringArr;
	FString fileLoc = FPaths::GameContentDir() + "HunterGenome.txt";
	FFileHelper::LoadANSITextFileToStrings(*fileLoc, NULL, fileStringArr);

	//format:
	//speed	size	sight	power	def	HP	fitness
	//15	100		25		10		15	300	0
	//15	100		25		10		15	300	0

	//from line 1 to line 2, those are the best 2 genomes.
	bestGenome.Empty();
	for (int i = 1; i < fileStringArr.Num(); i++) {
		if (fileStringArr[i] != "") {
			TArray<FString> tempStringArr;
			//get the parameters based on the tabs
			fileStringArr[i].ParseIntoArray(tempStringArr, TEXT("	"));
			//make it into float/int
			//	Genome(float inSpeed, float inSize, float inSight, int inPower, int inDef, int inHP, float inFitness) {
			float inSpeed = FCString::Atof(*tempStringArr[0]);
			float inSize = FCString::Atof(*tempStringArr[1]);
			float inSight = FCString::Atof(*tempStringArr[2]);
			int inPower = FCString::Atoi(*tempStringArr[3]);
			int inDef = FCString::Atoi(*tempStringArr[4]);
			int inHP = FCString::Atoi(*tempStringArr[5]);
			float inFitness = FCString::Atof(*tempStringArr[6]);
			Genome* newGenome = new Genome(inSpeed, inSize, inSight, inPower, inDef, inHP, inFitness);
			bestGenome.Push(newGenome);
		}
	}

}

void AEvolutionControler::saveGenome()
{
	//initialize, and make some buffers when writing file
	//can't use "\n"to make a new line, only using array could solve it.
	TArray<FString> textStringArr;
	//textStringArr.Push(TEXT("testing\n123\t456 78"));
	//textStringArr.Push(TEXT("africa is the best"));
	//temp. string 
	FString lineString = "";
	FString fileLoc = FPaths::ProjectContentDir() + "HunterGenome.txt";
	// first line should add it first
	textStringArr.Add("speed	size	sight	power	def	HP	fitness");
	//then other lines are the content.
	for (Genome* iGenome : bestGenome) {
		lineString=FString::SanitizeFloat(iGenome->speed)+"	"+
			FString::SanitizeFloat(iGenome->size) + "	"+
			FString::SanitizeFloat(iGenome->sight) + "	"+
			FString::FromInt(iGenome->power) + "	"+
			FString::FromInt(iGenome->def)+ "	"+
			FString::FromInt(iGenome->HP) + "	"+
			FString::SanitizeFloat(iGenome->fitness);
		textStringArr.Add(lineString);
	}
	//overwrite the whole file.
	FFileHelper::SaveStringArrayToFile(textStringArr, *fileLoc);

}

void AEvolutionControler::saveSettings()
{
	saveGenome();
	saveNetwork();
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
	FString fileLoc = FPaths::ProjectContentDir() + "HunterNeuro.txt";
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

}

void AEvolutionControler::loadNetwork()
{	
	//initialize, and make some buffers when reading file
	FString fileString, fLine;
	TArray<FString> fileStringArr;
	FString fileLoc = FPaths::GameContentDir() + "HunterNeuro.txt";
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

