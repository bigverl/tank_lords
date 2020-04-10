// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
    // Clamp relative speed of elevation
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

    // Change elevation
    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

    // Clamp elevation min/max
    auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
    
    SetRelativeRotation(FRotator(Elevation, 0, 0));
}