// Fill out your copyright notice in the Description page of Project Settings.

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

    //TODO PREVENT DOUBLE MOVEMENT
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

    //TODO PREVENT DOUBLE MOVEMENT
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

    //TODO PREVENT DOUBLE MOVEMENT
}

// Determine if move is valid
void UTankMovementComponent::RequestDirectMove(const FVector &MoveVelocity, bool bForceMaxSpeed)
{
    // No need to call super since we're replacing functionality

    auto TankName = GetOwner()->GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *TankName, *MoveVelocity.ToString());
}