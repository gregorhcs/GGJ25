// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionTile.h"


// Sets default values
ACollisionTile::ACollisionTile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACollisionTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollisionTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

