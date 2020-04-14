// Copyright Weston Mathews 2020

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * TankTurret is used to establish parameters for player's horizontal aiming
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class TANKLORDS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downward speed, and +1 is max upward movement
	void Rotate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 25; 
};
