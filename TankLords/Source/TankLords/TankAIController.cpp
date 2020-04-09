// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

// Upon game start,
void ATankAIController::BeginPlay()
{
    // Call parent begin play method
    Super::BeginPlay();

    // Assign player tank object to temporary variable
    auto PlayerTank = GetPlayerTank();
    // Check to see if tank is possessed
    if(PlayerTank)
    {
        // Output pawn being controlled by player
        UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
        
    }
    else // If player tank not found
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
    }
}

// Get AI Controlled Tank
ATank* ATankAIController::GetControlledTank() const
{
    
    return Cast<ATank>(GetPawn());
}

// Get Player Tank
ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    return Cast<ATank>(PlayerPawn);
}

