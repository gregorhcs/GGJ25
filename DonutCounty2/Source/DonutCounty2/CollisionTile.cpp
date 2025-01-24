// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionTile.h"


ACollisionTile::ACollisionTile()
{
	PrimaryActorTick.bCanEverTick = true;

	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	SetRootComponent(Plane);
}

void ACollisionTile::SetSize(float Size)
{
	SetActorRelativeScale3D(FVector(Size));
}

// Called when the game starts or when spawned
void ACollisionTile::BeginPlay()
{
	Super::BeginPlay();
	
}
