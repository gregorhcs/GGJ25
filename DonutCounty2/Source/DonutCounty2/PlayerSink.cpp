// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSink.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void APlayerSink::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (ULocalPlayer* LocalPlayer = Cast<APlayerController>(GetController())->GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			InputSystem->AddMappingContext(IMC, 0);
		}
	}
	
	auto* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInput->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APlayerSink::HandleOnMoveTriggered);
}

void APlayerSink::HandleOnMoveTriggered(const FInputActionValue& Value)
{
	const FVector2d Direction = Value.Get<FVector2d>();
	const FVector Direction3d = FVector3d(Direction.X, Direction.Y, 0.f);

	UE_LOG(LogTemp, Log, TEXT("%s"), *Direction.ToString())
	
	const FVector DrawStart = GetActorLocation() + 100 * GetActorForwardVector();
	DrawDebugLine(GetWorld(), DrawStart, DrawStart + Direction3d * 300, FColor::Blue);
	
	const float DeltaSeconds = GetWorld()->GetDeltaSeconds();
	FHitResult MoveHit;
	AddActorWorldOffset(Speed * DeltaSeconds * Direction3d, false, &MoveHit);
}
