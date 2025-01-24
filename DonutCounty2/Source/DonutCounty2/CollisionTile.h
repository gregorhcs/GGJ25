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
	ACollisionTile();

	void SetSize(float Size);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> Plane = nullptr;
};
