// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTJUMP_API UEnemyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	
	UEnemyComponent();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Speed = 100;
	int32 Health = 10;
	UPROPERTY()
	float DistanceMoved = 0;
	UPROPERTY()
	class AActor* Spline;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	virtual void Hurt(int32 Damage);

		
};
