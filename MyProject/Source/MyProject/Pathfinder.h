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

	APathNode* startNode;
	APathNode* endNode;
	FVector startPt;
	FVector endPt;
	priority_queue<NodeCost*, vector<NodeCost*>, NodeCost> frontier;
	TArray<NodeCost*> closeNode;
	bool isFound;

	static TArray<APathNode*> NodeArray;
	TArray<FVector> GeneratePath(FVector inStartPt, FVector inEndPt);

	//functions:
		//getNeighbours: output the connecting node
		//getCost: get the cost between 2 nodes
		//getHeuristic: get the distance between the checking node and end node
		//reset: reset every variables except statics.
		//search: create a link list for the close node to find the best path.
		//getNearestNode: find the nearest node for specific position
		//isNodeCostClosed: check if that node is existed in the closed list
	TArray<APathNode*> getNeighbours(NodeCost* inNode);
	float getCost(NodeCost* fromNode, NodeCost* toNode);
	float setHeuristic(NodeCost* inNode);
	void reset();
	void search();
	APathNode* getNearestNode(FVector inPos);
	bool isNodeCostClosed(APathNode* checkNode);
	//bool isCostOverWritable(float formerCost, float afterCost);

};
