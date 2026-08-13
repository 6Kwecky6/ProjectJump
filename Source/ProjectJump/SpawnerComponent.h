// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTJUMP_API USpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnerComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	TSubclassOf<AActor> EnemyToSpawn;
	int32 NumSpawned = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	int32 NumToSpawn = 10;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	FTimerHandle SpawnTimerHandle;
	UFUNCTION()
	virtual void SpawnEnemy();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
