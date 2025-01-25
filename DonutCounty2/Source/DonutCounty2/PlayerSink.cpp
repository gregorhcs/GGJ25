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
	const FVector2d RelativeDirection = Value.Get<FVector2d>();
	const FVector RelativeDirection3d = FVector3d(RelativeDirection.X, RelativeDirection.Y, 0.f);

	FVector ForwardXY = GetActorForwardVector();
	ForwardXY.Z = 0.f;
	const FVector Direction = ForwardXY.RotateAngleAxis(FRotator::NormalizeAxis(RelativeDirection3d.Rotation().Yaw + 90.f), FVector::UpVector);
	
	const float DeltaSeconds = GetWorld()->GetDeltaSeconds();
	FHitResult MoveHit;
	AddActorWorldOffset(Speed * DeltaSeconds * Direction, false, &MoveHit);
}
