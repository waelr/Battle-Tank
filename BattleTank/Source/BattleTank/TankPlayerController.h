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
	
private :

// Get Currently Possess pawn by this controller
	ATank* GetControlledTank() const;
 

	
	
	
};
