// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

// Forward Declarations
class UTankBarrel;

// Hold barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKLORDS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Default constructor
	UTankAimingComponent();

	// Set Barrel location
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// TOOD add SetTurretReference

	// Aim at specific tank
	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
		// Helper functions

	// Move barrel toward HitLocation
	void MoveBarrelTowards(FVector AimDirection);

		// Attributes
	UTankBarrel* Barrel = nullptr;
		
};
