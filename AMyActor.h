// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AMyActor.generated.h"

UCLASS()
class CPP_LEARN_API AAMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void RandomMove();
	FVector2d RandomStep();
	float Distance(FVector2D a, FVector2D b);
	void CreateEvent();
	
	FVector2d Location = FVector2d(0.0, 0.0);
	int TickCount = 0;
	int32 EventCount = 0;
	float TotalDistance = 0.0f;
};

