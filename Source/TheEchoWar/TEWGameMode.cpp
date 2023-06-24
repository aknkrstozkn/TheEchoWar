// Copyright Epic Games, Inc. All Rights Reserved.

#include "TEWGameMode.h"

#include "TEWCameraPawn.h"
#include "TEWPlayerController.h"
#include "UObject/ConstructorHelpers.h"

ATEWGameMode::ATEWGameMode()
{
	PlayerControllerClass = ATEWPlayerController::StaticClass();
	DefaultPawnClass = ATEWCameraPawn::StaticClass();
}