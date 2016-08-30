// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// how close can AI get to the player
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000;
	
private:
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
};
