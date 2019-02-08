#include "TankPlayerController.h"
#include "BattleTank.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is not posessed"))
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing %s"), *(ControlledTank->GetName()))
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

