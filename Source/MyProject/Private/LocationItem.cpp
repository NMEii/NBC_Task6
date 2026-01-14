// Fill out your copyright notice in the Description page of Project Settings.


#include "LocationItem.h"

ALocationItem::ALocationItem()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	StartLocation = FVector::ZeroVector;
	MaxDistance = 50.0f;
	MoveDirection = FVector::ForwardVector;

	// SceneComponent를 생성하고 루트 설정
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	// StaticMeshComponent를 생성, SceneComp에 Attach(하위종속)
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneComp);


	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));

	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Material/M_Basic.M_Basic"));

	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
}

void ALocationItem::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();	// 액터 생성 지점 가져오기
	UE_LOG(LogTemp, Warning, TEXT("시작 위치 : %s"), *StartLocation.ToString());

	// 방향은 제곱의 값이 1이여야 함. 
	MoveDirection.Normalize();	// 크기를 1로 만드는 함수. 즉, 방향 벡터만 남기는 함수.

	FVector ForwardVector = GetActorForwardVector();

	// 전방 벡터 삽입
	MoveDirection.X *= ForwardVector.X ;	
	MoveDirection.Y *= ForwardVector.Y;		
	MoveDirection.Z *= ForwardVector.Z;		

}

void ALocationItem::MoveActor(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	FVector MoveLocation = CurrentLocation + (MovingSpeed * MoveDirection * DeltaTime);
	
	// 이동거리
	FVector Distance = CurrentLocation - StartLocation;

	 
	SetActorLocation(MoveLocation);

	// 시작위치 기록 StartLocation
	// 현재위치 - 시작위치 = 이동거리 CurrentLocation - StartLocation = Distance
	// 이동거리(벡터) -> 길이	Distance 
	// 길이 -> 최대 이동길이 

	// 거리 변수 한 개더 생성
	
	if(Distance.Length() >= MaxDistance)
	{
		StartLocation = GetActorLocation();	// 액터 생성 지점 가져오기
		MoveDirection *= -1;
		UE_LOG(LogTemp, Warning, TEXT("시작 위치 : %s"), *StartLocation.ToString());
	}
}

void ALocationItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveActor(DeltaTime);
}

