// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetControlledTank()) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController controle le Tank %s"), *GetControlledTank()->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController ne controle pas le Tank"));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	ATank *TankPlayer = Cast<ATank>(GetPawn());
	if (!TankPlayer) return nullptr;
	return TankPlayer;
}

void Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("The Hell It Works"));

}