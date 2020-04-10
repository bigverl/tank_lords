// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h" // Put all includes above this

// Forward Declarations
class UTankBarrel;

UCLASS()
class TANKLORDS_API ATank : public APawn
{
	GENERATED_BODY()
	
public:	
	// Aim at specific location
	void AimAt(FVector HitLocation);

	// Set barrel reference
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

protected:
UTankAimingComponent* TankAimingComponent = nullptr;;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

			// ATTRIBUTES

	// Firing speed of projectile
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.f; // Starting value is 1000 m/s


	
};
