// Fill out your copyright notice in the Description page of Project Settings.

#include "Neuron.h"

Neuron::~Neuron()
{
}

Neuron::Neuron(unsigned numOutouts, unsigned myindex)
{
	//To tweak our learning rate
	learningRate = 0.1;
	alpha = 0.25;

	for (unsigned c = 0; c < numOutouts; c++) {
		m_outputWeights.Push(Connection());
		m_outputWeights.Last().weight = randomWeight();
	}

	m_myIndex = myindex;
}

void Neuron::feedForward(const Layer & prevLayer)
{
	double sum = 0.0;

	for (unsigned n = 0; n != prevLayer.Num(); n++)
	{
		sum += prevLayer[n].getOutputValue() * prevLayer[n].m_outputWeights[m_myIndex].weight;
	}

	m_outputValue = Neuron::transferFunction(sum);
}

void Neuron::calculateOutputGradients(double targetValue)
{
	double delta = targetValue - m_outputValue;
	m_gradient = delta * Neuron::transferFunctionDerivative(m_outputValue);
}

void Neuron::calculateHiddenGradients(const Layer &nextLayer)
{
	double dow = sumDOW(nextLayer);
	m_gradient = dow * Neuron::transferFunctionDerivative(m_outputValue);
}

void Neuron::updateInputWeights(Layer &previousLayer)
{
	for (unsigned n = 0; n != previousLayer.Num(); n++)
	{
		Neuron &neuron = previousLayer[n];
		double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;

		double newDeltaWeight =
			// training weight application learning rate
			learningRate * neuron.getOutputValue() * m_gradient +
			//a fraction of previous delta weight
			alpha * oldDeltaWeight;

		neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
		neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
	}
}

TArray<double> Neuron::getOutputWeight()
{
	TArray<double> outVector;
	//get all output weight from it to its connected neuron
	for (Connection& i : m_outputWeights) {
		outVector.Push(i.weight);
	}
	return outVector;
}

void Neuron::setOutputWeight(TArray<double>& inWeights)
{
	//overwrite the output weights from the network provided.
	for (int i = 0; i < m_outputWeights.Num(); i++) {
			m_outputWeights[i].weight = inWeights[i];
			//also reset the deltaweight to prevent abnormal neuron development.
			m_outputWeights[i].deltaWeight = 0;
	}
}

double Neuron::sumDOW(const Layer & nextLayer) const
{
	double sum = 0.0;

	for (unsigned n = 0; n != nextLayer.Num() - 1; n++)
	{
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}
	return sum;
}

double Neuron::transferFunction(double x)
{
	//tanh = outputrange [-1.0..1.0]
	return tanh(x);
}

double Neuron::transferFunctionDerivative(double x)
{
	return 1.0 - x * x;
}
