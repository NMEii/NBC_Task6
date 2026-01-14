// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LocationItem.generated.h"

UCLASS()
class MYPROJECT_API ALocationItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALocationItem();

protected:
	
	USceneComponent* SceneComp;
	UStaticMeshComponent* StaticMeshComp;

	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|MaxDistance");
	float MaxDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|MoveDirection");
	FVector MoveDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|MovingSpeed");
	float MovingSpeed = 20.0f;

	virtual void BeginPlay() override;
	void MoveActor(float DeltaTime);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
