// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKLORDS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public: 

	// Reference tank being possessed
	ATank* GetControlledTank() const;

	// Get Player Tank
	ATank* GetPlayerTank() const;

	// Methods to execute upon game start
	virtual void BeginPlay() override;

	// Aim at Player
	// void AimAt(Player);
};
