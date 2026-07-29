// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyComponent.h"
#include "Components/SplineComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UEnemyComponent::UEnemyComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Speed = 100;

	

	// ...
}


// Called when the game starts
void UEnemyComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Spline"), FoundActors);


	if (!FoundActors.IsEmpty())
	{
		Spline = FoundActors[0];
	}

	if (!Spline) {
		UE_LOG(LogTemp, Warning, TEXT("Spline not found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Spline found!"));
	}
	
}


// Called every frame
void UEnemyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (!Spline) {
		return;
	}


	USplineComponent* SplineComp =
		Spline->FindComponentByClass<USplineComponent>();


	DistanceMoved += Speed * DeltaTime;


	DistanceMoved = FMath::Min(
		DistanceMoved,
		SplineComp->GetSplineLength());
	


	FVector Pos = SplineComp->GetLocationAtDistanceAlongSpline(
		DistanceMoved,
		ESplineCoordinateSpace::World);
	

	FRotator Rotation = SplineComp->GetRotationAtDistanceAlongSpline(
		DistanceMoved,
		ESplineCoordinateSpace::World);

	GetOwner()->SetActorLocationAndRotation(Pos, Rotation);
}


void UEnemyComponent::Hurt(int32 Damage) {
	Health -= Damage;


	if (Health <= 0) {
		GetOwner()->Destroy();
	}
}

