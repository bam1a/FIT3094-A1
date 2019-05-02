// Fill out your copyright notice in the Description page of Project Settings.

#include "Pathfind.h"
#include "Wall.h"
#include "Creature.h"
#include "ConstructorHelpers.h"
#include <EngineGlobals.h>
#include "DrawDebugHelpers.h"
#include "Engine/GameEngine.h"
#include "EngineUtils.h"


// Sets default values
APathfind::APathfind()
{
	NodeArray.Empty();
	NodeArray4Show.Empty();
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	reset();
}

TArray<APathNode*> APathfind::NodeArray;


// Called when the game starts or when spawned
void APathfind::BeginPlay()
{
	//add all the APathNode to the array.
	for (TActorIterator<APathNode> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		//add only if the node type is not food.
		if ((*ActorItr->getNodeType()) != FString("Food")) {
			// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
			NodeArray.Add(*ActorItr);

		}
	}
	//add all path node to its array.
	Super::BeginPlay();
	for (APathNode* iNode : NodeArray) {
			NodeArray4Show.Add(iNode);
		
	}
	reset();
	
}

// Called every frame
void APathfind::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FVector> APathfind::GeneratePath(FVector inStartPt, FVector inEndPt)
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
	//add the last position and its nearest node to the output array
	outVectors.Add(endPt);
	//add the remainings to the array
	//there's no need to back trace if only start node is the end node.
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::FromInt(closeNode.Num()));
	if (closeNode.Num() > 1) {
		NodeCost* tempNodeCost = closeNode[closeNode.Num()-1];
		//loop the tempNode if there's stuff inside and until reached the start node.
		while (tempNodeCost != nullptr) {
			if (tempNodeCost->node != nullptr) {
				//make some randomness for the position?(todo)
				//todo...
				outVectors.Add(tempNodeCost->node->GetPosition());
				//set the parent node for next loop.
				tempNodeCost = tempNodeCost->parentNodeCost;
			}
			else {
				break;
			}
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::FromInt(outVectors.Num()));

	//and then output it.
	return outVectors;
}

TArray<APathNode*> APathfind::getNeighbours(APathNode * inNode)
{
	//get the array of neighbour nodes from the current node.
	TArray<APathNode*> outArray = *(inNode->GetNeighbourNode());
	return outArray;
}

float APathfind::getCost(NodeCost * fromNode, NodeCost * toNode)
{
	//the distance between each other is the cost
	float outCost = FVector::Distance(fromNode->node->GetPosition(), toNode->node->GetPosition());
	//if there's some preferable/avoidable path node, shall it reduce/add more cost?
	return outCost;
}

float APathfind::setHeuristic(NodeCost * inNode)
{
	//the distance between end point and the checking node is the heuristic
	float outHeuristic = FVector::Distance(inNode->node->GetPosition(), endNode->GetPosition());

	return outHeuristic;
}

void APathfind::reset()
{
	startNode = nullptr;
	endNode = nullptr;
	startPt = FVector::ZeroVector;
	endPt = FVector::ZeroVector;
	frontier.empty();
	closeNode.Empty();
	processedNode.Empty();
	isFound = false;

}

void APathfind::search()
{
	//initialize
	isFound = false;
	//create a new NodeCost for the starting node
	NodeCost* startingNodeCost = new NodeCost(startNode, 0.f, FVector::Distance(startNode->GetPosition(), endNode->GetPosition()));
	frontier.empty();
	frontier.push(startingNodeCost);
	processedNode.Push(startingNodeCost);
	//main loop
	//keep looping unless there's no more frontier queue or already found the end node.
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Orange, FString::FromInt(frontier.size()));
	while (frontier.size() > 0 && !isFound) {
		//set the current node cost combination as the top frontier node.
		NodeCost* current = frontier.top();
		//then close that node as well(as it assumed to reach goal "faster and optimal")
		closeNode.Push(current);
		//and then pop the node from frontier.
		frontier.pop();
		//make branches if the current node it's not a null pointer
		if (current->node != nullptr) {
			//if the current Node pointer is the end node
			if (current->node == endNode) {
				//set to true to terminate th loop
				isFound = true;
			}
			//if it's not 
			else {
				//if the current node has no neighbour, break it.
				GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::FromInt(current->node->GetNeighbourNode()->Num()));
				if (current->node->GetNeighbourNode()->Num() > 0 && (current->node->GetNeighbourNode()!=nullptr) ) {
					//loop all the neighbours from the current node
					GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Purple, FString::FromInt(getNeighbours(current->node).Num()));
					for (APathNode* next : getNeighbours(current->node)) {
						//find that node is closed or not
						//if that nodeCost it's not closed
						if (!isNodeCostClosed(next)&& next!=nullptr ) {
							//set its heuristic
							float inHeuristic = FVector::Distance(next->GetPosition(), endNode->GetPosition());
							//set the cost between current Node and next node+ the previous costs calculated before
							float inCost = current->cost + FVector::Distance(next->GetPosition(), current->node->GetPosition());
							//set the NodeCost for with current node cost object as the parent node
							//add it to the frontier
							NodeCost* nextNodeCost = new NodeCost(next, inCost, inHeuristic, current);
							frontier.push(nextNodeCost);
							processedNode.Push(nextNodeCost);
						}
					}
				}
				else {
					break;
				}
			}
		}
		//otherwise there's no way to keep looking forward
		else {
			break;
		}

	}

}

APathNode * APathfind::getNearestNode(FVector inPos)
{
	//set the checking distance to max val for initilzing
	//and a temp. distance var.
	float shortestDist = 30000.f;
	float tempDist = 30000.f;
	//set a node pointer to part with the distance above
	APathNode* shortestNode = nullptr;
	//loop all the path node elements
	for (APathNode* iNode : NodeArray) {
		//if there's a shorter, change that node and use that distance as ref.
		//if()
		tempDist = FVector::Distance(iNode->GetActorLocation(), inPos);
		if (tempDist < shortestDist) {
			shortestDist = tempDist;
			shortestNode = iNode;
		}
	}
	//output that node
	return shortestNode;
}

bool APathfind::isNodeCostClosed(APathNode * checkNode)
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

FVector APathfind::genRandomLocation(FVector initPos, float inRange, bool isNeedValidCheck, float inCheckRange)
{
	FVector outVector = FVector::ZeroVector;
	outVector.X = initPos.X + FMath::FRandRange((inRange*-1.f), inRange);
	outVector.Y = initPos.Y + FMath::FRandRange((inRange*-1.f), inRange);
	outVector.Z = 0.f;
	
		//check if the location is valid, if not do it until it's valid<--maybe in a new function?
		//condition to do: the valid check switch is label as true
		if (isNeedValidCheck) {
			while (!checkPosValid(outVector, inCheckRange)) {
				outVector.X = initPos.X + FMath::FRandRange((inRange*-1.f), inRange);
				outVector.Y = initPos.Y + FMath::FRandRange((inRange*-1.f), inRange);
				outVector.Z = 0.f;
			}
		}
		return outVector;
	}
	
bool APathfind::checkPosValid(FVector checkPos, float sweepArea) {
	//sweep the position according to the sweeping area

	//array of“FHitResult”that is going to store all the objects our hit detection registers
	TArray<FHitResult>OutHits;
	//get our locationandcreate a sphere collider.
	FVector location = checkPos;
	FCollisionShape CheckSphere = FCollisionShape::MakeSphere(sweepArea);

	//perform a“SweepMultiByChannel”which creates a shape based onthe last parameter, located at the position in the 2nd/3rd parameter.2nd/3rd parameter are the start and end points of a“Sweep”of the shape.
	//Any objects that overlap are then stored in the first parameter(our TArray)
	bool isHit = GetWorld()->SweepMultiByChannel(OutHits, location, location, FQuat::Identity, ECC_WorldStatic, CheckSphere);

	if (isHit) {
		//loop throughall our objects(autocasting them),get their mesh component and then if that was successful, apply a force to that object. 
		//The force has a start, size, amount, falloff and a boolean checking if to NOT use mass.
		for (auto& Hit : OutHits) {
			//if it has a wall, or a creature, or a food pallet, return false
			AWall* wall = Cast<AWall>((Hit.GetActor()));
			if (wall) {
				return false;
			}
			ACreature* creature = Cast<ACreature>((Hit.GetActor()));
			if (creature) {
				return false;
			}
		}
	}
	else {
		return true;

	}
	return true;
}
