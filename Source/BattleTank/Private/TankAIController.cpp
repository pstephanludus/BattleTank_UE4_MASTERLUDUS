// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetPlayerTank()) {
		UE_LOG(LogTemp, Warning, TEXT("AIController trouve le PlayerController: %s"), *GetPlayerTank()->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController ne trouve pas le PlayerController:"));
	}
}

 void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}


ATank* ATankAIController::GetPlayerTank() const
{
	APawn *TankPlayer = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!TankPlayer) return nullptr;
	return Cast<ATank>(TankPlayer);
}

