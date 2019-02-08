// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetAiControlledTank();
	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AiController is not posessed"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AiController posessing %s"), *(ControlledTank->GetName()))
	}
}


ATank* ATankAIController::GetAiControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

