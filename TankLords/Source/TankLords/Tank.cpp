// Fill out your copyright notice in the Description page of Project Settings.
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create Aiming Component
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Set barrel reference point
void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

// Set turret reference point
void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

// Aim at specific location
void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}


// Fire Cannon
void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("FIRING"));
	if(!Barrel)
	{
		UE_LOG(LogTemp, Error, TEXT("NO LOCAL BARREL SET"));
		return;
	}

	// Spawn projectile at socket location
	//FVector BarrelSocketLocation = Barrel->GetSocketLocation(FName("Projectile"));
	//FRotator BarrelSocketRotation = Barrel->GetSocketRotation(FName("Projectile"));

	//GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, BarrelSocketLocation, BarrelSocketRotation);

	GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint, 
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
		);


	
}