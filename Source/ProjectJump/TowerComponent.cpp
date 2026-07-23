// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerComponent.h"
#include "Components/SphereComponent.h"

// Sets default values for this component's properties
UTowerComponent::UTowerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTowerComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Start!"));

	GetWorld()->GetTimerManager().SetTimer(AttackTimerHandle, this, &UTowerComponent::Attack, 3.0f, true);


	USphereComponent* AttackRange = GetOwner()->FindComponentByClass<USphereComponent>();

	if (AttackRange)
	{
		AttackRange->OnComponentBeginOverlap.AddDynamic(
			this,
			&UTowerComponent::OnSphereBeginOverlap);

		AttackRange->OnComponentEndOverlap.AddDynamic(
			this,
			&UTowerComponent::OnSphereEndOverlap);
	}
	
}


// Called every frame
void UTowerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTowerComponent::Attack()
{
	
	UEnemyComponent* BestEnemyComponent = nullptr;
	AActor* BestEnemy = nullptr;


	for (UEnemyComponent* EnemyComponent : Enemies) {
		AActor* Enemy = EnemyComponent->GetOwner();


		if (!BestEnemy) {
			BestEnemy = Enemy;
			BestEnemyComponent = EnemyComponent;
			continue;
		}

		if (EnemyComponent->DistanceMoved > BestEnemyComponent->DistanceMoved) {
			BestEnemy = Enemy;
			BestEnemyComponent = EnemyComponent;
		}
	}
	
	if (!BestEnemy) {
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Attacking %s"), *BestEnemy->GetName());
}


void UTowerComponent::OnSphereBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{

	if (!OtherActor) {
		return;
	}


	UEnemyComponent* EnemyComponent = OtherActor->FindComponentByClass<UEnemyComponent>();



	if (EnemyComponent)
	{
		Enemies.AddUnique(EnemyComponent);
		UE_LOG(LogTemp, Warning, TEXT("Enemy entered range: %s"), *OtherActor->GetName());
	}
}

void UTowerComponent::OnSphereEndOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (!OtherActor) {
		return;
	}


	UEnemyComponent* EnemyComponent = OtherActor->FindComponentByClass<UEnemyComponent>();



	if (EnemyComponent)
	{
		Enemies.Remove(EnemyComponent);
		UE_LOG(LogTemp, Warning, TEXT("Enemy exited range: %s"), *OtherActor->GetName());
	}
}
