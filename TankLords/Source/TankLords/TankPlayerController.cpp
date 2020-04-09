// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    
    Super::BeginPlay();

    // Store controlled tank
    auto ControlledTank = GetControlledTank();

    // Check to see if tank is possessed
    if(ControlledTank)
    {
        // Output pawn being controlled
        UE_LOG(LogTemp, Warning, TEXT("%s Controlled"), *(ControlledTank->GetName()));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController NOT Connected to Tank"));
    }

    UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}

// Move turret toward crosshair
void ATankPlayerController::AimTowardsCrosshair()
{
    if(!GetControlledTank()) { return; }

    FVector HitLocation ; // Out parameter
    if(GetSightRayHitLocation(HitLocation))
    {
        //Tell controlled tank to aim at this point
        GetControlledTank()->AimAt(HitLocation);
    }

}

// Get world location if linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
    // Find Crosshair Position
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);

    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

    // De-Project screen position of crosshair to a world direction
    FVector LookDirection;
    if(GetLookDirection(ScreenLocation, LookDirection))
    {   
        // Line-trace along that look direction, and see what we hit (up to max range)
        return GetLookVectorHitLocation(LookDirection, HitLocation);
    }

    return true;
}

// Get Player's Look Direction
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
    // Get world direction
    FVector CameraWorldLocation; // To be discarded
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

// Get Player's Hit Location
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
    FHitResult HitResult;
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    auto EndLocation   = StartLocation + (LookDirection * LineTraceRange);
    if(GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
    {
        HitLocation = HitResult.Location;
        return true;
    }

    return false; // didn't succeed
}

// Get Controlled Tank
ATank* ATankPlayerController::GetControlledTank() const { return Cast<ATank>(GetPawn()); }

