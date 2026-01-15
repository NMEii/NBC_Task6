// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class MYPROJECT_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	
	USceneComponent* SceneComp;

	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawner Setting");
	TSubclassOf<AActor> ActorSpawn;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawner Setting");
	int SpawnCount;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawner Setting");
	FVector SpawnRange;

	UFUNCTION(BlueprintCallable, Category = "Spawner Functions")
	void SpawnActors();
};
