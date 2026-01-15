// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationActor.generated.h"

UCLASS()
class MYPROJECT_API ARotationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotationActor();



protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Item|Componenets");
	USceneComponent* SceneComp;				// 루트 컴포넌트

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Item|Components");
	UStaticMeshComponent* StaticMeshComp;	// 스태틱 매시 컴포넌트

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|RotationSpeed");
	float RotationSpeed = 90.0f;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Rotating(float DeltaTime);
};
