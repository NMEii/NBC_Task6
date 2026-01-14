// Fill out your copyright notice in the Description page of Project Settings.


#include "LocationItem.h"

ALocationItem::ALocationItem()
{
 	
	PrimaryActorTick.bCanEverTick = true;

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
	
}

void ALocationItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

