// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PrimaryActorTick.bCanEverTick = true;
	

	UE_LOG(LogTemp, Warning, TEXT("From TankPlayerController::BeginPlay()"))

		auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerContoller not posses a pawn tank "))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT(" PlayerContoller posses a pawn tank : %s"), *(ControlledTank->GetName()))
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	 
	AimTowardCrosshair();

//	UE_LOG(LogTemp, Warning,TEXT("From TankPlayerController::Tick() "))
}

ATank* ATankPlayerController::GetControlledTank() const
{
	ATank * MyTankPawn = Cast<ATank>(GetPawn());
	return MyTankPawn;

}

void ATankPlayerController::AimTowardCrosshair() {

	if (!GetControlledTank()) return;

	FVector HitLocation; // out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect" , is going to line trace
	{
	   UE_LOG(LogTemp, Warning, TEXT("Hit Location : %s"), *(HitLocation.ToString()))
	  // tell controlled tank to aim at this point.
	}
	
	    
}

// Get World location if  linetrace through crosshair
// true if hit landscape.
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const {


	HitLocation = FVector(1.0f);
	

	return true;
}

