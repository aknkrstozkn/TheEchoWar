// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "TEWPlayerController.generated.h"

UCLASS()
class ATEWPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATEWPlayerController();

protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

	void OnMovementInput(const FInputActionValue& Value);

private:
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;
	
	/** Camera Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* CameraAxisInputAction;
};