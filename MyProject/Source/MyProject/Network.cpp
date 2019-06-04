// Fill out your copyright notice in the Description page of Project Settings.

#include "Network.h"
#include <cassert>
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

Network::Network()
{
}

Network::~Network()
{
}

Network::Network(const TArray<unsigned> &topology)
{
	unsigned numLayers = topology.Num();
	for (unsigned layerNum = 0; layerNum < numLayers; layerNum++)//<--bug here?
	{
		m_layers.Push(Layer());
		unsigned numOutputs = layerNum == topology.Num() - 1 ? 0 : topology[layerNum + 1];

		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; neuronNum++)
		{
			m_layers.Last().Push(Neuron(numOutputs, neuronNum));
			GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Red, TEXT("Made a neuron!"));
		}

		//bias neuron
		m_layers.Last().Last().setOutputValue(1.0);

	}
}

void Network::feedForward(const TArray<double>& inputValues)
{
	//error check
	assert(inputValues.Num() == m_layers[0].Num() - 1);

	//assign the input vals to input neurons
	for (unsigned i = 0; i != inputValues.Num(); i++)
	{
		m_layers[0][i].setOutputValue(inputValues[i]);
	}

	//forwardprop
	for (unsigned layerNum = 1; layerNum != m_layers.Num(); layerNum++)
	{
		Layer &prevLayer = m_layers[layerNum - 1];
		for (unsigned n = 0; n != m_layers[layerNum].Num() - 1; n++)
		{
			m_layers[layerNum][n].feedForward(prevLayer);
		}
	}
}

void Network::backPropagation(const TArray<double>& targetValues)
{
	//calculate overall net error (root mean square)
	Layer &outputLayer = m_layers.Last();
	m_error = 0.0;

	for (unsigned n = 0; n != outputLayer.Num() - 1; n++)
	{
		double delta = targetValues[n] - outputLayer[n].getOutputValue();
		m_error += delta * delta;
	}
	m_error /= outputLayer.Num() - 1; //Get average error squared
	m_error = sqrt(m_error); //RMS

	//calculate output layer gradients 
	for (unsigned n = 0; n != outputLayer.Num() - 1; n++)
	{
		outputLayer[n].calculateOutputGradients(targetValues[n]);
	}

	//calculate gradients on hidden layers
	for (unsigned layerNum = m_layers.Num() - 2; layerNum > 0; layerNum--)
	{
		Layer &hiddenLayer = m_layers[layerNum];
		Layer &nextLayer = m_layers[layerNum + 1];

		for (unsigned n = 0; n != hiddenLayer.Num() - 1; n++)
		{
			hiddenLayer[n].calculateHiddenGradients(nextLayer);
		}
	}

	//For all layers from outputs to first hidden layer, update connections

	for (unsigned layerNum = m_layers.Num() - 1; layerNum > 0; layerNum--)
	{
		Layer &layer = m_layers[layerNum];
		Layer &previousLayer = m_layers[layerNum - 1];

		for (unsigned n = 0; n != layer.Num() - 1; n++)
		{
			layer[n].updateInputWeights(previousLayer);
		}
	}
}

//Set Output Results in resultValues
void Network::getResult(TArray<double>& resultValues) const
{
	resultValues.Empty();

	for (unsigned n = 0; n != m_layers.Last().Num() - 1; n++)
	{
		resultValues.Push(m_layers.Last()[n].getOutputValue());
	}
}

void Network::displayReport(const TArray<double> &inputValues, const TArray<double>& targetValues, const TArray<double>& resultValues)
{
	FString outString;
	//print string
	//GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Red, TEXT("Screen Message"));
	//print vector
	//GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Orange, FString::Printf(TEXT("My Location is: %s"), *GetActorLocation().ToString()));
	/*
	Report format:
	Neuron topology structure
	Input value
	Target value
	errors
	Output weight for each node with it(all nodes except the final layer)
	*/
	//clear the debug screen
	GEngine->ClearOnScreenDebugMessages();
	//topology
	outString = "topology: ";
	for (Layer i : m_layers) {
		outString += (FString::FromInt(i.Num() - 1));;
		outString += " , ";
	}
	GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Black, outString);
	//inputs
	outString = "input value: ";
	for (double i : inputValues) {
		outString += (FString::SanitizeFloat(i, 1));
		outString += " , ";
	}
	GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Green, outString);
	//target output value
	outString = "expected output: ";
	for (double i : targetValues) {
		outString += (FString::SanitizeFloat(i, 1));
		outString += " , ";
	}
	GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Green, outString);

	//actual output
	outString = "actual output: ";
	for (double i : resultValues) {
		outString += FString::SanitizeFloat(i, 1);
		outString += "->";
		outString += FString::SanitizeFloat(round(i), 1);
		outString += " , ";
	}
	//for (Neuron& i : m_layers[m_layers.Num() - 1]) {
	//	outString += (FString::SanitizeFloat(i.getOutputValue(), 1));
	//	outString += " , ";
	//}
	GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Red, outString);

	//error
	outString = "training error: ";
	outString += (FString::SanitizeFloat(m_error, 1));
	if (m_error > 0.5f) {
		GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Red, outString);
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Green, outString);
	}
	//output weight for each layer each neuron to each outputing neuron
	for (int i = 0; i < m_layers.Num() - 1; i++) {
		//int neuronIndex = 0;
		for (int k = 0; k < m_layers[i].Num() - 1; k++) {
			Neuron iNeuron = m_layers[i][k];
			outString = "Layer ";
			outString += FString::FromInt(i);
			outString += " ";
			outString += "neuron ";
			outString += FString::FromInt(k);
			outString += ": ";

			TArray<double> tempWeights = iNeuron.getOutputWeight();

			for (int j = 0; j < tempWeights.Num(); j++) {
				outString += FString::SanitizeFloat(tempWeights[j], 1);
				outString += " , ";
			}

			GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Blue, outString);
			//neuronIndex++;
		}
	}
}

void Network::overwriteNeurons(TArray<TArray<TArray<double>>>& inNeuro)
{
	//set all layer's neuron
	//loop the list of all layers
	for (int i = 0; i < inNeuro.Num(); i++) {
		//loop the list of all output weights of the neuron
		for (int j = 0; j < inNeuro[i].Num(); j++) {
			//overwrite the output weight
			TArray<double> tempNeuroWeight = inNeuro[i][j];
			m_layers[i][j].setOutputWeight(tempNeuroWeight);
		}
	}
}
