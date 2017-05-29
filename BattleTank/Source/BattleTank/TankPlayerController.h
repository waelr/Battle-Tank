// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public :
	
	// override BeginPlay() of AAcotor.
	void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private :

// Get Currently Possess pawn by this controller
	ATank* GetControlledTank() const;
// Start moving the barrel so that the shot 
// hit where the crosshair point instersect the world. 
	void AimTowardCrosshair();
// return  out paramter , trur if hit something like landscape.
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	
	
	
};
