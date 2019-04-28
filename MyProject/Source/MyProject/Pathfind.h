// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <queue>
#include <vector>
#include "GameFramework/Actor.h"
#include "PathNode.h"
#include "Pathfind.generated.h"

using namespace std;

UCLASS()
class MYPROJECT_API APathfind : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APathfind();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//miniclass NodeCost: a class that contains a path node, a cost value, and a parent node
	struct NodeCost {
		APathNode* node;
		float cost;
		float heuristic;
		NodeCost* parentNodeCost = nullptr;

		NodeCost() {}
		//constructor
		NodeCost(APathNode* inNode, float inCost, float inHeuristic, NodeCost* inParentNode = nullptr) {
			node = inNode;
			cost = inCost;
			heuristic = inHeuristic;
			parentNodeCost = inParentNode;
		}

		//this operator will let the prio. queue keep sort in decending order
		//which let the top be the lowest cost.
		bool operator() (const NodeCost* node1, const NodeCost* node2, float epslion = 0.00001f) {
			return (node1->cost + node1->heuristic) > (node2->cost + node2->heuristic);
		}
	};

	//variable for searching
	//startNode: the starting node when searching
	//endNode: the goal node when searching
	//startPt: the start location
	//endPt: the goal position
	//isFound: the switch which determines the path is found or not.
	APathNode* startNode;
	APathNode* endNode;
	FVector startPt;
	FVector endPt;
	bool isFound;

	//list for the search uses
	//frontier: a queue of node cost combination that keeps set itself in decending position to keep the smallest value at top
	//closeNode: the node cost combination that is already expended, which shouldn't be revisit as it causes node loop
	//processedNode:all the node cost combination will be saved here, prevent garbrage when reusing.
	priority_queue<NodeCost*, vector<NodeCost*>, NodeCost> frontier;
	TArray<NodeCost*> closeNode;
	TArray<NodeCost*> processedNode;

	//functions:
	//getNeighbours: output the connecting node
	//getCost: get the cost between 2 nodes
	//getHeuristic: get the distance between the checking node and end node
	//reset: reset every variables except statics.
	//search: create a link list for the close node to find the best path.
	//getNearestNode: find the nearest node for specific position
	//isNodeCostClosed: check if that node is existed in the closed list
	TArray<APathNode*> getNeighbours(APathNode* inNode);
	float getCost(NodeCost* fromNode, NodeCost* toNode);
	float setHeuristic(NodeCost* inNode);
	void reset();
	void search();
	APathNode* getNearestNode(FVector inPos);
	bool isNodeCostClosed(APathNode* checkNode);
	//bool isCostOverWritable(float formerCost, float afterCost);
	FVector genRandomLocation(FVector initPos, float inRange, bool isNeedValidCheck = false, float inCheckRange = 1.f);
	bool checkPosValid(FVector checkPos, float sweepArea);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//function for external classes use
	//nodeArray: the array which contains all the path nodes
	//GeneratePath: generate the path for each
	//UPROPERTY(VisibleAnywhere)
	static TArray<APathNode*> NodeArray;
	TArray<FVector> GeneratePath(FVector inStartPt, FVector inEndPt);



};
