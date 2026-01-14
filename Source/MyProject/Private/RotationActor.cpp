

#include "RotationActor.h"

ARotationActor::ARotationActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// SceneComponent를 생성하고 루트 설정
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	// StaticMeshComponent를 생성, SceneComp에 Attach(하위종속)
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneComp);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));


	if (MeshAsset.Succeeded())	// 파일 찾기 성공시
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Material/M_Basic.M_Basic"));

	if (MaterialAsset.Succeeded()) // 파일 찾기 성공시
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	SetActorScale3D(FVector(0.8f, 0.8f, 30.0f));
	SetActorRotation(FRotator(90.0f, 0.0f, 0.0f));
}

void ARotationActor::BeginPlay()
{
	Super::BeginPlay();
	
}

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
	AddActorLocalRotation(FRotator(0.0f, 0.0f, RotationSpeed * DeltaTime));
}

