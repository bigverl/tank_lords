// Copyright Weston Mathews 2020

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
    // Clamp relative speed of Rotation
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
    auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto Rotation = RelativeRotation.Yaw + RotationChange;
    SetRelativeRotation(FRotator(0, Rotation, 0));
}

