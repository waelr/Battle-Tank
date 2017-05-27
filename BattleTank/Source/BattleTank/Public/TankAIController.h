// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	// Get Currently Possess pawn by this controller
	ATank* GetControlledTank() const;
	// - override BeginPlay() of AAcotor. 
	// - override keyword indicate we want to 
	//   override this method.
	// - virtual tell us we are to override this method
	//   by child classes
	virtual void BeginPlay() override;
	
	
};
