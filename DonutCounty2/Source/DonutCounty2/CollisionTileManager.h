// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollisionTile.h"
#include "CollisionTileManager.generated.h"

UCLASS(Blueprintable)
class DONUTCOUNTY2_API ACollisionTileManager : public AActor
{
	GENERATED_BODY()

public:
	ACollisionTileManager();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACollisionTile> CollisionTileClass;

	// extent in cm
	UPROPERTY(EditDefaultsOnly)
	float Extent = 200.f;

	// size of each tile in cm
	UPROPERTY(EditDefaultsOnly)
	float Resolution = 5.f;

	UPROPERTY()
	TArray<TWeakObjectPtr<ACollisionTile>> CollisionTiles = {};
	
public:
	virtual void Tick(float DeltaTime) override;
};
