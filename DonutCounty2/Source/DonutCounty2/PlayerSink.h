// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnhancedInput/Public/InputMappingContext.h"
#include "PlayerSink.generated.h"

UCLASS(Blueprintable)
class DONUTCOUNTY2_API APlayerSink : public APawn
{
	GENERATED_BODY()

public:
	// - APawn
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// --

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Speed = 400.f;
	
protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> IMC = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> IA_Move = nullptr;

	void HandleOnMoveTriggered(const FInputActionValue& Value);
};
