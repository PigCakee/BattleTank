// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if(!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AiController can't find player tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AiController found player: %s"), *(PlayerTank->GetName()))
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) 
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerPawn);
	}
}


ATank* ATankAIController::GetAiControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

