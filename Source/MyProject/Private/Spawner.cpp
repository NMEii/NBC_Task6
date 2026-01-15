// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "Kismet/KismetMathLibrary.h" // 랜덤 위치 계산을 위한 헤더

// Sets default values
ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	SpawnCount = 10;
	SpawnRange = FVector(300.0f, 300.0f, 100.0f);
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnActors();
}

void ASpawner::SpawnActors()
{
	if (!ActorSpawn) return; // 소환할 클래스가 설정되지 않았다면 리턴

	UWorld* World = GetWorld();

	if (World)
	{
		for (int i = 0; i < SpawnCount; ++i)
		{
			// 1. 현재 매니저 위치 기준 랜덤 위치 계산
			FVector CenterLocation = GetActorLocation();

			// UKismetMathLibrary를 사용하여 범위 내 랜덤 벡터 생성
			FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(CenterLocation, SpawnRange);

			// 2. 회전값 설정 (필요시 랜덤으로 설정 가능)
			FRotator RandomRotation;
			RandomRotation.Yaw = UKismetMathLibrary::RandomFloatInRange(0.f, 360.f);   // Z축 랜덤 값
			RandomRotation.Pitch = UKismetMathLibrary::RandomFloatInRange(0.f, 360.f); // Y축 랜덤 값
			RandomRotation.Roll = UKismetMathLibrary::RandomFloatInRange(0.f, 360.f);  // X축 랜덤 값

			// 3. 스폰 파라미터 설정 (충돌 시 처리 등)
			FActorSpawnParameters SpawnParams;
			//SpawnParams.Owner = this;
			//SpawnParams.Instigator = GetInstigator();	
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

			// 4. 실제 소환 실행
			World->SpawnActor<AActor>(ActorSpawn, RandomLocation, RandomRotation, SpawnParams);
		}
	}
}


