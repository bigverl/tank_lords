// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put all includes above this

// Forward Declarations
class UTankAimingComponent;
class UTankBarrel;
class AProjectile;

UCLASS()
class TANKLORDS_API ATank : public APawn
{
	GENERATED_BODY()
	
public:	
	// Set barrel reference
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// Set turret reference
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	// Aim at specific location
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

protected:
UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

			// ATTRIBUTES
	// Implement projectile blueprint into tank BP
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;
	
	// Firing speed of projectile
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000.f; // Starting value is 1000 m/s

	// Firing rate limitation
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3.f;
	double LastFireTime = 0.f;

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;
	
	
};
