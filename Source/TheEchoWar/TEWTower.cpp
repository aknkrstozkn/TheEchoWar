#include "TEWTower.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetMathLibrary.h"

ATEWTower::ATEWTower()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	TowerHeadParent = CreateDefaultSubobject<USceneComponent>(TEXT("TowerHeadParent"));
	TowerHeadParent->SetupAttachment(RootComponent);
	
	TowerHeadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TowerHead"));
	TowerHeadMesh->SetupAttachment(TowerHeadParent);
	
	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	Collider->SetupAttachment(RootComponent);
	Collider->SetSphereRadius(120.f);
}

void ATEWTower::BeginPlay()
{
	Super::BeginPlay();
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ATEWTower::OnActorEnter);
	Collider->OnComponentEndOverlap.AddDynamic(this, &ATEWTower::OnActorExit);

	// Get Data
	check(TowerDataTable);
	TArray<FTEWTowerData*> DataArray;
	TowerDataTable->GetAllRows<FTEWTowerData>(TEXT("ATEWTower::BeginPlay"), DataArray);
	TowerData = DataArray[TowerLevel];
}

void ATEWTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Rotate Head
	if (EnemiesInRange.IsEmpty())
	{
		return;
	}
	const AActor* FirstEnemy = EnemiesInRange[0];
	TowerHeadParent->SetRelativeRotation(UKismetMathLibrary::FindLookAtRotation(TowerHeadParent->GetComponentLocation(), FirstEnemy->GetActorLocation()));
}

void ATEWTower::OnActorEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	EnemiesInRange.AddUnique(OtherActor);
}

void ATEWTower::OnActorExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	EnemiesInRange.Remove(OtherActor);
}
