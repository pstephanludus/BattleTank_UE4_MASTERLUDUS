// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

		virtual void Tick(float DeltaTime) override;



private:
	
		//Retour du GetPawn
		ATank* GetControlledTank() const;
		
		// Start the tank moving the marrel so that a shot would hit where the crosshair intersects the world
		void AimTowardsCrosshair();

		bool GetSightRayHitLocation(FVector& OutHitLocation) const;

		UPROPERTY(EditAnywhere)
			float CrossHairXLocation = 0.5;
		UPROPERTY(EditAnywhere)
			float CrossHairYLocation = 0.3333;
		UPROPERTY(EditAnywhere)
			float LineTraceRange = 1000000;

		bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
		bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	
};
