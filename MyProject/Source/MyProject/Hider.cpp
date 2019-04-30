// Fill out your copyright notice in the Description page of Project Settings.

#include "Hider.h"

AHider::AHider() :ACreature()
{
	//reset all array/pointer content when start up(try prevent memory leakage and crash)
	delete h_StateMachine;
	h_StateMachine = nullptr;
	delete shelterTarget;
	shelterTarget = nullptr;

	//Get Sphere Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Wedge_A.Shape_Wedge_A"));
	if (VisualAsset.Succeeded())
	{
		Mesh->SetStaticMesh(VisualAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/assignmentContent/Material.Material"));
	if (FoundMaterial.Succeeded())
	{
		DynamicMaterialInst = UMaterialInstanceDynamic::Create((UMaterial*)FoundMaterial.Object, Mesh);
		DynamicMaterialInst->SetVectorParameterValue(FName(TEXT("Colour")), FLinearColor(0.0, 0.0, 1.0, 1.0));
		Mesh->SetMaterial(0, DynamicMaterialInst);
	}

}
void AHider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	h_StateMachine->Tick(DeltaTime);

}

void AHider::BeginPlay()
{
	Super::Super::BeginPlay();

	setPathfinder();
	//initialize the parameeter
	initialize();
	cType = HIDER;
	//set target hide time

	hideTime = 60.f;
	//set default state
	h_StateMachine->ChangeState(STATE_WANDER);

}

AShelter * AHider::getShelter(TArray<FHitResult>* inHits)
{
	//if the hit result array has a shelter node, output it immediatly.
	for (auto& Hit : *inHits) {
		AShelter* shelter = Cast<AShelter>((Hit.GetActor()));
		if (shelter) {
			return shelter;
		}
	}
	//otherwise just return a null pointer, other function will recognize.
	return nullptr;
}

AHunter * AHider::getHunter(TArray<FHitResult>* inHits)
{
	//if the hit result array has a hunter object, output it immediately.
	for (auto& Hit : *inHits) {
		AHunter* hunter = Cast<AHunter>((Hit.GetActor()));
		if (hunter) {
			return hunter;
		}
	}
	//otherwise just return a null pointer, other function will recognize.
	return nullptr;
}

void AHider::stateRegister()
{
	h_StateMachine = new StateMachine<Creature_State, AHider>(this, STATE_DO_NOTHING);
	//STATE_WANDER,
	h_StateMachine->RegisterState(STATE_WANDER, &AHider::State_Wander_OnEnter, &AHider::State_Wander_OnTick, &AHider::State_Wander_OnExit);
	//	STATE_FLEE,
	h_StateMachine->RegisterState(STATE_FLEE, &AHider::State_Flee_OnEnter, &AHider::State_Flee_OnTick, &AHider::State_Flee_OnExit);
	//	STATE_SPAWN,
	h_StateMachine->RegisterState(STATE_SPAWN, &AHider::State_Spawn_OnEnter, &AHider::State_Spawn_OnTick, &AHider::State_Spawn_OnExit);
	//	STATE_DIE,
	h_StateMachine->RegisterState(STATE_DIE, &AHider::State_Die_OnEnter, &AHider::State_Die_OnTick, &AHider::State_Die_OnExit);
	//	STATE_HIT,
	h_StateMachine->RegisterState(STATE_HIT, &AHider::State_Hit_OnEnter, &AHider::State_Hit_OnTick, &AHider::State_Hit_OnExit);
	//	STATE_STANDBY
	h_StateMachine->RegisterState(STATE_STANDBY, &AHider::State_Standby_OnEnter, &AHider::State_Standby_OnTick, &AHider::State_Standby_OnExit);
	//STATE_HIDER_TOSHELTER
	h_StateMachine->RegisterState(STATE_HIDER_TOSHELTER, &AHider::State_ToShelter_OnEnter, &AHider::State_ToShelter_OnTick, &AHider::State_ToShelter_OnExit);

}

void AHider::State_Wander_OnEnter(void){Super::State_Wander_OnEnter();}

void AHider::State_Wander_OnTick(float f_DeltaTime)
{
	Super::State_Wander_OnTick(f_DeltaTime);
	//make some if cases to find enemies and food
	TArray<FHitResult> hitResult = getSurroundings();
	AShelter* tempShelterTarget = getShelter(&hitResult);
	AHunter* tempHunterTarget = getHunter(&hitResult);
	if (tempShelterTarget != nullptr) {
		//when wandering make sure it won't be the same shelter target
		if (shelterTarget != tempShelterTarget) {
			shelterTarget = tempShelterTarget;
			h_StateMachine->ChangeState(STATE_HIDER_TOSHELTER);

		}
	}
	if (tempHunterTarget != nullptr) {
		cTargetCreature = Cast<ACreature>(tempHunterTarget);
		h_StateMachine->ChangeState(STATE_FLEE);
	}

}

void AHider::State_Wander_OnExit(void){SetLastState(h_StateMachine->GetCurrentState());}

void AHider::State_Spawn_OnEnter(void)
{
	Super::State_Spawn_OnEnter();

}

void AHider::State_Spawn_OnTick(float f_DeltaTime)
{
	Super::State_Spawn_OnTick(f_DeltaTime);
	h_StateMachine->ChangeState(STATE_WANDER);

}

void AHider::State_Spawn_OnExit(void){	SetLastState(h_StateMachine->GetCurrentState());}

void AHider::State_Flee_OnTick(float f_DeltaTime)
{
	//if the target is less than its sight's twice or it's not die, keep fleeing
	if (FVector::Distance(cTargetCreature->GetPos(), cPosition)>(cSight * 2) || cTargetCreature != nullptr) {
		//get the target's position and get the fleeing direction
		cTargetPosition = cPosition - cTargetCreature->GetPos();
		//and let the actor move
		move(f_DeltaTime, true);
	}
	else {
		//otherwise get back to wandering mode.
		h_StateMachine->ChangeState(cLastState);
	}

}

void AHider::State_Flee_OnExit(void) { SetLastState(h_StateMachine->GetCurrentState()); }

void AHider::State_Hit_OnTick(float f_DeltaTime)
{
	//if time's up, change the status back to normal(might be overloaded when needed.
	if (cTimer >= cTime) {
		h_StateMachine->ChangeState(cLastState);
	}
	else {
		cTimer += f_DeltaTime;
	}

}
void AHider::State_Hit_OnExit(void) { SetLastState(h_StateMachine->GetCurrentState()); }

void AHider::State_Standby_OnEnter(void)
{
	Super::State_Standby_OnEnter();
	cTimer = 0;
}

void AHider::State_Standby_OnTick(float f_DeltaTime)
{

	if (cTimer >= hideTime) {
		h_StateMachine->ChangeState(STATE_SPAWN);
	}
	else {
		cTimer += f_DeltaTime;
	}


	Super::State_Standby_OnTick(f_DeltaTime);
	//if hunter is on its sight, flee.
	TArray<FHitResult> hitResult = getSurroundings();
	AHunter* tempHunterTarget = getHunter(&hitResult);
	if (tempHunterTarget != nullptr) {
		cTargetCreature = Cast<ACreature>(tempHunterTarget);
		h_StateMachine->ChangeState(STATE_FLEE);
	}
	

}

void AHider::State_Standby_OnExit(void){SetLastState(h_StateMachine->GetCurrentState());}

void AHider::State_ToShelter_OnEnter(void)
{
	//generate a path of the target
	cPathlist = cPathfinder->GeneratePath(cPosition, shelterTarget->GetPosition());
	//set target location to the first index of the path list
	cPathlistID = cPathlist.Num() - 1;
	cTargetPosition = cPathlist[cPathlistID];

}

void AHider::State_ToShelter_OnTick(float f_DeltaTime)
{
	if (FVector::Distance(cTargetPosition, cPosition) < (cSize)) {
		//change to another index when not finished its path.
		//it reaches the shelter location, change state to standby.
		if (cTargetPosition == cPathlist[0] || cPathlistID == 0) {
			h_StateMachine->ChangeState(STATE_STANDBY);
		}
		else {
			cPathlistID -= 1;
			cTargetPosition = cPathlist[cPathlistID];
		}
	}
	//if hunter is on its sight, flee.
	TArray<FHitResult> hitResult = getSurroundings();
	AHunter* tempHunterTarget = getHunter(&hitResult);
	if (tempHunterTarget != nullptr) {
		cTargetCreature = Cast<ACreature>(tempHunterTarget);
		h_StateMachine->ChangeState(STATE_FLEE);
	}

	//and let the actor move
	move(f_DeltaTime, false);

}

void AHider::State_ToShelter_OnExit(void) { SetLastState(h_StateMachine->GetCurrentState()); }


