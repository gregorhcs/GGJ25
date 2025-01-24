// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollisionTileManager.generated.h"

UCLASS(Blueprintable)
class DONUTCOUNTY2_API ACollisionTileManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACollisionTileManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
