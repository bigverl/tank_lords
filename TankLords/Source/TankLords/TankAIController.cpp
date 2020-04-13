// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

// Upon game start,
void ATankAIController::BeginPlay()
{
    // Call parent begin play method
    Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    auto ControlledTank = Cast<ATank>(GetPawn());
    if(PlayerTank)
    {
        // Move towards player
        MoveToActor(PlayerTank, AcceptanceRadius);

        // Aim at player
        ControlledTank->AimAt(PlayerTank->GetActorLocation());
        
        // TODO Fire if ready
        ControlledTank->Fire(); // TODO limit firing rate
        
    }
}

