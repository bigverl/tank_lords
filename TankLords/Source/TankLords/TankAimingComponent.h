// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKLORDS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Default constructor
	UTankAimingComponent();

	// Set Barrel location
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

	// Aim at specific tank
	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UStaticMeshComponent* Barrel = nullptr;
		
};
