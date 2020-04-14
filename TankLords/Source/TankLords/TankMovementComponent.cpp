// Copyright Weston Mathews 2020

#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    if(!LeftTrackToSet || !RightTrackToSet)
    {
        UE_LOG(LogTemp, Error, TEXT("NO TRACK TO SET"));
        return;
    }
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
    UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);

    if(!LeftTrack || !RightTrack)
    {
        UE_LOG(LogTemp, Error, TEXT("NO TRACK TO SET"));
        return;
    }
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);

    //TODO PREVENT DOUBLE MOVEMENT
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
    UE_LOG(LogTemp, Warning, TEXT("Intend turn right throw: %f"), Throw);

    if(!LeftTrack || !RightTrack)
    {
        UE_LOG(LogTemp, Error, TEXT("NO TRACK TO SET"));
        return;
    }
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
    UE_LOG(LogTemp, Warning, TEXT("Intend move backward throw: %f"), Throw);

    if(!LeftTrack || !RightTrack)
    {
        UE_LOG(LogTemp, Error, TEXT("NO TRACK TO SET"));
        return;
    }
    LeftTrack->SetThrottle(-Throw);
    RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
    UE_LOG(LogTemp, Warning, TEXT("Intend turn left throw: %f"), Throw);

    if(!LeftTrack || !RightTrack)
    {
        UE_LOG(LogTemp, Error, TEXT("NO TRACK TO SET"));
        return;
    }
    LeftTrack->SetThrottle(-Throw);
    RightTrack->SetThrottle(Throw);
}

// Determine if move is valid
void UTankMovementComponent::RequestDirectMove(const FVector &MoveVelocity, bool bForceMaxSpeed)
{
    // No need to call super since we're replacing functionality

    // Forward/Backward movement
    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto AIForwardIntention = MoveVelocity.GetSafeNormal();
    auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
    IntendMoveForward(ForwardThrow);

    // Rotation/Turning movement
    auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
    IntendTurnRight(RightThrow);
}