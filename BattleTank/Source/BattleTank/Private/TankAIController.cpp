// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("From TankAIController::BeginPlay()"))

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI-Contoller not posses a pawn tank "))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT(" AI-Contoller posses a pawn tank : %s"), *(ControlledTank->GetName()))
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	ATank * EnemyTankPawn = Cast<ATank>(GetPawn());
	return EnemyTankPawn;

}

