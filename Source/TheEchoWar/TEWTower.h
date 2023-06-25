#pragma once

#include "CoreMinimal.h"
#include "TEWTowerData.h"
#include "GameFramework/Actor.h"
#include "TEWTower.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class UDataTable;

UCLASS()
class THEECHOWAR_API ATEWTower : public AActor
{
	GENERATED_BODY()

public:
	ATEWTower();

	UFUNCTION()
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	FTEWTowerData* TowerData;	
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tower", meta = (AllowPrivateAccess = true))
	UDataTable* TowerDataTable;	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tower", meta = (AllowPrivateAccess = true))
	int32 TowerLevel = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tower", meta = (AllowPrivateAccess = true))
	USceneComponent* TowerHeadParent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tower", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* TowerHeadMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tower", meta = (AllowPrivateAccess = true))
	USphereComponent* Collider;

	UPROPERTY()
	TArray<AActor*> EnemiesInRange;

	UFUNCTION()
	void OnActorEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnActorExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};