// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionTileManager.h"


ACollisionTileManager::ACollisionTileManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACollisionTileManager::BeginPlay()
{
	Super::BeginPlay();

	// FActorSpawnParameters SpawnParams;
	// SpawnParams.Owner = this;
	//
	// const float OriginX = GetActorLocation().X;
	// const float OriginY = GetActorLocation().Y;
	//
	// TileNumPerLine = FMath::FloorToInt(Extent / Resolution);
	//
	// const float HalfExtent = Extent/2;
	//
	// const float StartX = OriginX - HalfExtent;
	// const float StartY = OriginY - HalfExtent;
	//
	// const int32 TotalCollisionTilesNum = TileNumPerLine * TileNumPerLine;
	// UE_LOG(LogTemp, Warning, TEXT("CollisionTileManager: Spawning %i collision tiles."), TotalCollisionTilesNum);
	//
	// CollisionTiles.Reserve(TotalCollisionTilesNum);
	//
	// FVector SpawnLocation = GetActorLocation();
	//
	// for (int32 PosX = 0; PosX < TileNumPerLine; PosX++)
	// {
	// 	for (int32 PosY = 0; PosY < TileNumPerLine; PosY++)
	// 	{
	// 		SpawnLocation.X = StartX + PosX * Resolution;
	// 		SpawnLocation.Y = StartY + PosY * Resolution;
	// 		
	// 		ACollisionTile* NewTile = GetWorld()->SpawnActor<ACollisionTile>(CollisionTileClass.Get(), SpawnLocation, FRotator::ZeroRotator, SpawnParams);
	// 		NewTile->SetSize(Resolution / 100.f);
	// 		
	// 		CollisionTiles.Add(NewTile);
	// 	}
	// }
}

void ACollisionTileManager::ForEachTilePosition(FTileCallback Callback)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;

	const float OriginX = GetActorLocation().X;
	const float OriginY = GetActorLocation().Y;

	TileNumPerLine = FMath::FloorToInt(Extent / Resolution);

	const float HalfExtent = Extent/2;
	
	const float StartX = OriginX - HalfExtent;
	const float StartY = OriginY - HalfExtent;

	const int32 TotalCollisionTilesNum = TileNumPerLine * TileNumPerLine;
	UE_LOG(LogTemp, Warning, TEXT("CollisionTileManager: Spawning %i collision tiles."), TotalCollisionTilesNum);
	
	//CollisionTiles.Reserve(TotalCollisionTilesNum);
	
	FVector SpawnLocation = GetActorLocation();
	
	for (int32 PosX = 0; PosX < TileNumPerLine; PosX++)
	{
		for (int32 PosY = 0; PosY < TileNumPerLine; PosY++)
		{
			SpawnLocation.X = StartX + PosX * Resolution;
			SpawnLocation.Y = StartY + PosY * Resolution;

			Callback.Execute(SpawnLocation, Resolution / 100.f);
			
			// ACollisionTile* NewTile = GetWorld()->SpawnActor<ACollisionTile>(CollisionTileClass.Get(), SpawnLocation, FRotator::ZeroRotator, SpawnParams);
			// NewTile->SetSize(Resolution / 100.f);
			
			//CollisionTiles.Add(NewTile);
		}
	}
}

