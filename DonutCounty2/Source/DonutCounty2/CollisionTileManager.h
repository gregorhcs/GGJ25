// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollisionTile.h"
#include "CollisionTileManager.generated.h"

DECLARE_DYNAMIC_DELEGATE_TwoParams(FTileCallback, FVector, Location, float, Scale);

UCLASS(Blueprintable)
class DONUTCOUNTY2_API ACollisionTileManager : public AActor
{
	GENERATED_BODY()

public:
	ACollisionTileManager();

	UFUNCTION(BlueprintCallable)
	void ModifySinkRadiusInTiles(float Multiplier);
	
protected:
	UFUNCTION(BlueprintCallable)
	void ForEachTilePosition(FTileCallback Callback);
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACollisionTile> CollisionTileClass;

	// extent in cm
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Extent = 200.f;

	// size of each tile in cm
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Resolution = 5.f;

	UPROPERTY(EditDefaultsOnly)
	int SinkRadiusInTiles = 20;

	UPROPERTY()
	TArray<TWeakObjectPtr<ACollisionTile>> CollisionTiles = {};

	int32 TileNumPerLine = -1;
};
