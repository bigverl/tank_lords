// Copyright Weston Mathews 2020

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKLORDS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private: 
	ATank* GetControlledTank() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Start tank moving barrel so that shot will hit where crosshair intersects in world
	void AimTowardsCrosshair();

	// Determine if ray hits landscape
	bool GetSightRayHitLocation(FVector &HitLocation) const;

	// Get player's look direction
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;

	// Get player's hit location
	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;

	virtual void BeginPlay() override;


	// Screen X and Y position
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333f;

	// Maximum Range of Weapon
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f;
};
