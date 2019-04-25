// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PathNode.h"
#include "Creature.h"
#include <queue>
#include <vector>


using namespace std;
/**
 * 
 */
class MYPROJECT_API Pathfinder
{
public:
	//miniclass NodeVal: a class that contains a path node and a cost value
	struct NodeCost {
		APathNode* node;
		float cost;
		float heuristic;
		APathNode* parentNode=nullptr;

		NodeCost(){}

		NodeCost(APathNode* inNode, float inCost) {
			node = inNode;
			cost = inCost;
		}

		//this operator will let the prio. queue keep sort in decending order
		//which let the top be the lowest cost.
		bool operator() (const NodeCost* node1, const NodeCost* node2, float epslion = 0.00001f) {
			return node1->cost > node2->cost;
		}
	};


	Pathfinder();
	//Pathfinder(FVector fromPos, FVector toPos);
	~Pathfinder();

	APathNode* startPt;
	APathNode* endPt;
	priority_queue<NodeCost*, TArray<NodeCost*>, NodeCost>* frontier;
	TArray<NodeCost*> closeNode;
	bool isFound;

	static TArray<APathNode*> NodeArray;
	static TArray<FVector> GeneratePath(FVector inStartPt, FVector inEndPt);

	TArray<APathNode*>getNeighbours(NodeCost* currentNode);
	float getCost(NodeCost* fromNode, NodeCost* toNode);
	float setHeuristic(NodeCost* inNode);
	void reset();
	void search();
};
