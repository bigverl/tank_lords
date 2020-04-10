// Fill out your copyright notice in the Description page of Project Settings.
#include "TankBarrel.h"
#include "TankAimingComponent.h"

// Default Constructor
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Set Barrel location
void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Aim at specific location
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	// Protect pointer. Should probably have been done in header, tbh
	if (!Barrel) { return; }

	// Declare Launch Velocity
	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace	
	);
	// Calculate OutLaunchVelocity
	if(bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);

	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Error, TEXT("%f: NO AIMING SOLUTION FOUND"), Time);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Get difference between current barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	// LOGGING
	auto TankName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("DeltaRotator is: %s"), *DeltaRotator.ToString());

	Barrel->Elevate(DeltaRotator.Pitch); // TODO THIS MIGHT BE BROKEN
	
}
