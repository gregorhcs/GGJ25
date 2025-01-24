// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollisionTile.generated.h"

UCLASS(Blueprintable)
class DONUTCOUNTY2_API ACollisionTile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACollisionTile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
