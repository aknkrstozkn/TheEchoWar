#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TEWTowerData.generated.h"

USTRUCT(BlueprintType)
struct THEECHOWAR_API FTEWTowerData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Tower Data")
	int32 Level = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Tower Data", meta=(ClampMin="0", ClampMax="1000"))
	float Range = 300.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Tower Data", meta=(ClampMin="0"))
	float Damage = 300.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Tower Data", meta=(ClampMin="0"))
	float FireSpeed = 300.f;
};