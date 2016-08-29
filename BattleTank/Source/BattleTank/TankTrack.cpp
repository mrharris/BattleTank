// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	UE_LOG(LogTemp, Warning, TEXT("TRack ticking"))
	auto SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());
	
	// work out required acc this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector(); // a = s / t
	
	// calc and apply sideways force f = m * a
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2; // 2 tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); // get Tank static mesh component
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
