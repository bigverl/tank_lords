// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
    // TODO Clamp throttle value so player can't overdrive
    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce; // FVector of force applied
    auto ForceLocation = GetComponentLocation(); // FVector of track

    // Get the actor in which force will be applied. Need to upcast to primitive component to apply physics
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);


}