// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationActor.h"

// Sets default values
ARotationActor::ARotationActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// /Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'
	// /Script/Engine.Material'/Engine/EditorShellMaterials/M_ShellMaster.M_ShellMaster'
	// SceneComponent를 생성하고 루트 설정
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	// StaticMeshComponent를 생성, SceneComp에 Attach(하위종속)
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneComp);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));


	if (MeshAsset.Succeeded())	// 파일 찾기 성공시
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Engine/EditorShellMaterials/M_ShellMaster.M_ShellMaster"));

	if (MaterialAsset.Succeeded()) // 파일 찾기 성공시
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
}

// Called when the game starts or when spawned
void ARotationActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		Rotating(DeltaTime);
	}
}

void ARotationActor::Rotating(float DeltaTime)
{
	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
}

