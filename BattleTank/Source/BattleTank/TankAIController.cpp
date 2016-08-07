// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT(""))

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI cant find player tank"));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found player %s"), *(PlayerTank->GetName()));
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// if AI has found a player tank
	if (GetPlayerTank())
	{
		// TODO move towards player
		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// fire when ready
	}
}