// Copyright Epic Games, Inc. All Rights Reserved.

#include "TEWPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ATEWPlayerController::ATEWPlayerController()
{
	bShowMouseCursor = false;
	DefaultMouseCursor = EMouseCursor::Default;
}

void ATEWPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void ATEWPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(CameraAxisInputAction, ETriggerEvent::Triggered, this, &ATEWPlayerController::OnMovementInput);
	}
}

void ATEWPlayerController::OnMovementInput(const FInputActionValue& Value)
{
	if (APawn* MovePawn = GetPawn())
	{
		const FVector InputValue = Value.Get<FVector>().GetSafeNormal();
		MovePawn->AddMovementInput(FVector{InputValue.Y, InputValue.X, 0.f});
	}
}