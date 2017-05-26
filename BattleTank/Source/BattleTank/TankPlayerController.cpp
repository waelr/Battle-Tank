// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("From TankPlayerController::BeginPlay()"))

		auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerContoller not posses a pawn tank "))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT(" PlayerContoller posses a pawn tank : %s"), *(ControlledTank->GetName()))
	}

}

ATank* ATankPlayerController::GetControlledTank() const
{
	ATank * MyTankPawn = Cast<ATank>(GetPawn());
	return MyTankPawn;

}


