// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TrackTrack is used to set maximum driving force and to apply forces to the tank
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class TANKLORDS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BluePrintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
};
