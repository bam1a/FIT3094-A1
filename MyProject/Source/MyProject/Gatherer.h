// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creature.h"
#include "Food.h"
#include "Gatherer.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AGatherer : public ACreature
{
	GENERATED_BODY()
public:
	enum Creature_State {
		STATE_TOEAT=10,
		STATE_EATING
	};
	virtual void Tick(float DeltaTime) override;


private:
	AFood * eatingTarget;
	int happiness, happinessLimit;


	//STATE_WANDER:wandering in another place(will be overwriten by others but will act as a super::blah(blah) ) <--target, after finishing up the node properties
	virtual void State_Wander_OnEnter(void) override;
	virtual void State_Wander_OnTick(float f_DeltaTime) override;
	virtual void State_Wander_OnExit(void) override;
	//STATE_SPAWN: spawning new creature based on its status but with some varieties based on some randomness
	virtual void State_Spawn_OnEnter(void) override;
	virtual void State_Spawn_OnTick(float f_DeltaTime) override;
	virtual void State_Spawn_OnExit(void) override;
	//STATE_TOEAT: moving towards to the food pallet which detected
	void State_ToEat_OnEnter(void);
	void State_ToEat_OnTick(float f_DeltaTime);
	void State_ToEat_OnExit(void);
	//STATE_EATING: a moment that eating the food pallet
	void State_Eating_OnEnter(void);
	void State_Eating_OnTick(float f_DeltaTime);
	void State_Eating_OnExit(void);


};
