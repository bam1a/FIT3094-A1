// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Neuron.h"
#include <vector>
#include "CoreMinimal.h"

/**
 * 
 */
class MYPROJECT_API Network
{
	typedef TArray<Neuron> Layer;
public:
	Network();
	~Network();

	Network(const TArray<unsigned> &topology);

	void feedForward(const TArray<double> &inputValues);
	void backPropagation(const TArray<double> &targetValues);
	void getResult(TArray<double> &resultValues) const;

	// this function is to show a report, output every neuron's output weight
	void displayReport(const TArray<double> &inputValues, const TArray<double> &targetValues, const TArray<double> &resultValues);

	//overwrite every neuron's output weight, even the bias
	void overwriteNeurons(TArray<TArray<TArray<double>>> inNeuro);

private:
	double m_error;
	TArray<Layer> m_layers;
};
