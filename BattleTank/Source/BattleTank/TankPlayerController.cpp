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
	 //  UE_LOG(LogTemp, Warning, TEXT("Look Direction : %s"), *(HitLocation.ToString()))
	 
		   
		   // tell controlled tank to aim at this point.
	}
	
	    
}

// Get World location if  linetrace through crosshair
// true if hit landscape.
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const {


//	HitLocation = FVector(1.0f);
	
	/* Find the crosshair position in pixel coordinate
	  - %s : string 
	  - %f : float
	  - %d : integer
	*/
	// size of our viewport.
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY); // get viewport size.
	/*UE_LOG(LogTemp, Warning,TEXT("ViewportSizeX : %d , ViewportSizeY : %d"),
		ViewportSizeX, ViewportSizeY)
  */ // remeber we set the white dot in UI at (.5x,.3y) of the screen
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation,
		ViewportSizeY * CrossHairYLocation);
//	UE_LOG(LogTemp, Warning, TEXT("Screen Location : %s"), *(ScreenLocation.ToString()))
	
// 'de-project' the screen position of the the crosshair to the world direction.
	 FVector WorldDirection;
	 if (GetLookDirection(ScreenLocation, WorldDirection)) {

	UE_LOG(LogTemp, Warning, TEXT("Look Direction : %s"),*(WorldDirection.ToString()))
	}
	
	// line-trace along that look direction. and see what hit ( up to max. range)



	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const{
	
	FVector CameraWorldLocation; // no need for this.
	
	return(DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	    ));

}


