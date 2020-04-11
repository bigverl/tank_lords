// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
    // TODO Clamp throttle value so player can't overdrive

    auto Name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);
}