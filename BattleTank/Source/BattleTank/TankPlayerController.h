// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	// start moving the tank so that a shot would hit the crosshair intersection
	void AimTowardsCrosshair();

	// return OUT parameter, true if hit occurs
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	// deproject screen position of cross hair to world direction
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;



	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333f;

	float LineTraceRange = 10.f * 1000.f * 100.f;
};
