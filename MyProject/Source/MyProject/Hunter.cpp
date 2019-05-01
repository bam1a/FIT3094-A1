// Fill out your copyright notice in the Description page of Project Settings.

#include "Hunter.h"

AHunter::AHunter() :ACreature()
{
	//reset all array/pointer content when start up(try prevent memory leakage and crash)
	delete p_StateMachine;
	p_StateMachine = nullptr;
	delete prayTarget;
	prayTarget = nullptr;

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
		DynamicMaterialInst->SetVectorParameterValue(FName(TEXT("Colour")), FLinearColor(1.0, 0.0, 0.0, 1.0));
		Mesh->SetMaterial(0, DynamicMaterialInst);
	}

}

void AHunter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	p_StateMachine->Tick(DeltaTime);
}

void AHunter::BeginPlay()
{
	Super::Super::BeginPlay();

	setPathfinder();
	//initialize the parameeter
	initialize();
	cType = HUNTER;

	//set target chasing time
	chaseTime = 30.f;
	//set default state
	p_StateMachine->ChangeState(STATE_WANDER);
}

ACreature * AHunter::getPray(TArray<FHitResult>* inHits)
{
	//if the hit result array has a non hunter creature, output it immediatly.
	for (auto& Hit : *inHits) {
		ACreature* pray = Cast<ACreature>((Hit.GetActor()));
		if (pray) {
			if (pray->getCreatureType() != HUNTER) {
				return pray;
			}
		}
	}
	//otherwise just return a null pointer, other function will recognize.
	return nullptr;
}

void AHunter::stateRegister()
{
	p_StateMachine = new StateMachine<Creature_State, AHunter>(this, STATE_DO_NOTHING);
	//STATE_WANDER,
	p_StateMachine->RegisterState(STATE_WANDER, &AHunter::State_Wander_OnEnter, &AHunter::State_Wander_OnTick, &AHunter::State_Wander_OnExit);
	//	STATE_FLEE,
	p_StateMachine->RegisterState(STATE_FLEE, &AHunter::State_Flee_OnEnter, &AHunter::State_Flee_OnTick, &AHunter::State_Flee_OnExit);
	//	STATE_SPAWN,
	p_StateMachine->RegisterState(STATE_SPAWN, &AHunter::State_Spawn_OnEnter, &AHunter::State_Spawn_OnTick, &AHunter::State_Spawn_OnExit);
	//	STATE_DIE,
	p_StateMachine->RegisterState(STATE_DIE, &AHunter::State_Die_OnEnter, &AHunter::State_Die_OnTick, &AHunter::State_Die_OnExit);
	//	STATE_HIT,
	p_StateMachine->RegisterState(STATE_HIT, &AHunter::State_Hit_OnEnter, &AHunter::State_Hit_OnTick, &AHunter::State_Hit_OnExit);
	//STATE_HUNTER_CHASE
	p_StateMachine->RegisterState(STATE_HUNTER_CHASE, &AHunter::State_Chase_OnEnter, &AHunter::State_Chase_OnTick, &AHunter::State_Chase_OnExit);

}

void AHunter::State_Wander_OnEnter(void){	Super::State_Wander_OnEnter();}

void AHunter::State_Wander_OnTick(float f_DeltaTime)
{
	Super::State_Wander_OnTick(f_DeltaTime);
	TArray<FHitResult> hitResult = getSurroundings();
	ACreature* tempPrayTarget = getPray(&hitResult);
	//chase if there's a pray
	if (tempPrayTarget != nullptr) {
		prayTarget = tempPrayTarget;
		p_StateMachine->ChangeState(STATE_HUNTER_CHASE);
	}

}

void AHunter::State_Wander_OnExit(void) { SetLastState(p_StateMachine->GetCurrentState()); }

void AHunter::State_Spawn_OnEnter(void)
{
	Super::State_Spawn_OnEnter();

}

void AHunter::State_Spawn_OnTick(float f_DeltaTime)
{
	Super::State_Spawn_OnTick(f_DeltaTime);
	p_StateMachine->ChangeState(STATE_WANDER);
	//todo: spawn new creature
}
void AHunter::State_Spawn_OnExit(void) { SetLastState(p_StateMachine->GetCurrentState()); }

void AHunter::State_Flee_OnTick(float f_DeltaTime)
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
		p_StateMachine->ChangeState(cLastState);
	}

}
void AHunter::State_Flee_OnExit(void) { SetLastState(p_StateMachine->GetCurrentState()); }

void AHunter::State_Hit_OnTick(float f_DeltaTime)
{
	//if time's up, change the status back to normal(might be overloaded when needed.
	if (cTimer >= cTime) {
		p_StateMachine->ChangeState(cLastState);
	}
	else {
		cTimer += f_DeltaTime;
	}

}

void AHunter::State_Hit_OnExit(void) { SetLastState(p_StateMachine->GetCurrentState()); }

void AHunter::State_Chase_OnEnter(void)
{
}

void AHunter::State_Chase_OnTick(float f_DeltaTime)
{
}

void AHunter::State_Chase_OnExit(void){	SetLastState(p_StateMachine->GetCurrentState());}

