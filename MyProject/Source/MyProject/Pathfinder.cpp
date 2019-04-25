// Fill out your copyright notice in the Description page of Project Settings.

#include "Pathfinder.h"

Pathfinder::Pathfinder()
{
}


Pathfinder::~Pathfinder()
{
}

TArray<APathNode*> Pathfinder::NodeArray;

TArray<FVector> Pathfinder::GeneratePath(FVector inStartPt, FVector inEndPt)
{
	TArray<FVector> outVectors;

	reset();
	startPt = inStartPt;
	endPt = inEndPt;
	//get the nearby node for start and end point
	startNode = getNearestNode(startPt);
	endNode = getNearestNode(endPt);
	//create the path
	search();
	//back trace from end node to the start node as vectors
	//add the end point for the path goal
	//and then output it.
	return outVectors;
}

TArray<APathNode*> Pathfinder::getNeighbours(NodeCost * inNode)
{
	//get the array of neighbour nodes from the current node.
	TArray<APathNode*> outArray = *(inNode->node->GetNeighbourNode());
	return outArray;
}

float Pathfinder::getCost(NodeCost * fromNode, NodeCost * toNode)
{
	//the distance between each other is the cost
	float outCost= FVector::Distance(fromNode->node->GetPosition(), toNode->node->GetPosition());
	//if there's some preferable/avoidable path node, shall it reduce/add more cost?
	return outCost;

}

float Pathfinder::setHeuristic(NodeCost * inNode)
{
	//the distance between end point and the checking node is the heuristic
	float outHeuristic = FVector::Distance(inNode->node->GetPosition(), endNode->GetPosition());

	return outHeuristic;
}

void Pathfinder::reset()
{
	startNode, endNode = nullptr;
	startPt,endPt = FVector::ZeroVector;
	frontier.empty();
	closeNode.Empty();
	isFound = false;
}

void Pathfinder::search()
{
}

APathNode * Pathfinder::getNearestNode(FVector inPos)
{
	//set the limit to max for initilzing and a temp. distance var.
	float shortestDist = numeric_limits<float>::max();
	float tempDist = 0.f;
	//set a node pointer with to part with the distance above
	APathNode* shortestNode=nullptr;
	//loop all the path node elements
	for (APathNode* iNode : NodeArray) {
		//if there's a shorter, change that node and use that distance as ref.
		tempDist = FVector::Distance(iNode->GetPosition(), inPos);
		if (tempDist < shortestDist) {
			shortestDist = tempDist;
			shortestNode = iNode;
		}
	}
	//output that node
	return shortestNode;
}

bool Pathfinder::isNodeCostClosed(APathNode * checkNode)
{
	//check each node in close node list
	for (NodeCost* iNode : closeNode) {
		//if there's a node that's mentioned, return true as that node is closed already.
		if (checkNode == iNode->node) {
			return true;
		}
	}
	//otherwise output false
	return false;
}
