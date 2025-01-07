// Fill out your copyright notice in the Description page of Project Settings.

#include "AMyActor.h"

// Sets default values
AAMyActor::AAMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("시작 좌표 : (%f, %f)"), Location.X, Location.Y);
}

// Called every frame
void AAMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (TickCount < 10)
	{
		RandomMove();
		UE_LOG(LogTemp, Warning, TEXT("현재 좌표 : (%f, %f)"), Location.X, Location.Y);
		TickCount++;
		if (TickCount >= 10)
		{
			UE_LOG(LogTemp, Display, TEXT("총 이동 거리 : (%f)"), TotalDistance);
			UE_LOG(LogTemp, Display, TEXT("총 이벤트 횟수 : (%d)"), EventCount);
		}
	}
}

void AAMyActor::RandomMove()
{
	FVector2d RandomLocation = RandomStep();
	
	// UE_LOG(LogTemp, Warning, TEXT("랜덤 좌표 : (%f, %f)"), RandomLocation.X, RandomLocation.Y);
	this->Location += RandomLocation;

	float Distance = this->Distance(Location, this->Location + RandomLocation);
	TotalDistance += Distance;
	UE_LOG(LogTemp, Display, TEXT("이동 거리 : (%f)"), Distance);
}

FVector2d AAMyActor::RandomStep()
{
	float DeltaTime = GetWorld()->GetTimeSeconds();
	int32 Seed = (int32)(DeltaTime*10000000);
	
	FRandomStream random(Seed);
	FVector2D RandomLocation;
	
	RandomLocation.X = (float)random.RandRange(0,1);
	RandomLocation.Y = (float)random.RandRange(0,1);

	if (random.RandRange(0,1) == 1)
	{
		CreateEvent();
	}
	return RandomLocation;
}

float AAMyActor::Distance(FVector2D a, FVector2D b)
{
	return FVector2D::Distance(a, b);
}

void AAMyActor::CreateEvent()
{
	UE_LOG(LogTemp, Error, TEXT("이벤트 발생!!!!!!"));
	EventCount++;
}


