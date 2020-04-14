// Copyright Weston Mathews 2020


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce; // FVector of force applied
    auto ForceLocation = GetComponentLocation(); // FVector of track

    // Get the actor in which force will be applied. Need to upcast to primitive component to apply physics
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);


}