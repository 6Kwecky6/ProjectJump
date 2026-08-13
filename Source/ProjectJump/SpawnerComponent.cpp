// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerComponent.h"

// Sets default values for this component's properties
USpawnerComponent::USpawnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &USpawnerComponent::SpawnEnemy, 3.0f, true);
	
}


// Called every frame
void USpawnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USpawnerComponent::SpawnEnemy()
{
	UE_LOG(LogTemp, Warning, TEXT("Spawning"));
	FVector SpawnLocation = FVector(0.0f, 0.0f, 0.0f);//GetOwner()->GetActorLocation() + GetOwner()->GetActorForwardVector() * 100.0f;
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);//GetOwner()->GetActorRotation();

	FActorSpawnParameters SpawnParams;

	GetWorld()->SpawnActor<AActor>(EnemyToSpawn, SpawnLocation, SpawnRotation, SpawnParams);


	NumSpawned++;

	//spawned enough. Stop timer
	if (NumSpawned >= NumToSpawn) {
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
	}
}