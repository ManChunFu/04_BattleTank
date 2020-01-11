// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
		return nullptr;
	else
		return Cast<ATank>(PlayerPawn);
}

void  ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetAIControlledTank();
	if (!ControlledTank)
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank."))
	else
		UE_LOG(LogTemp, Warning, TEXT("AIController possesing %s"), *(ControlledTank->GetName()))


	ATank* PlayerTank = GetPlayerTank();

	if (!PlayerTank)
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank."))
	else
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()))

}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank())
	{
		// TODO Move towards the player
		// Aim towards the player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if ready
	}
}
