// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NdorphinCharacter.h"
#include "GameFramework/Controller.h"
#include "Components/InputComponent.h"
#include "Engine/Engine.h"

// Sets default values
ANdorphinCharacter::ANdorphinCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANdorphinCharacter::BeginPlay()
{
	Super::BeginPlay();
	//SetDirection(GetActorLocation().Y);

	//ListOfStates = FindField<UEnumProperty>(GetClass(), TEXT("ListOfAlteredStates"));
}

void ANdorphinCharacter::Move(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		//set facing direction
		SetDirection(Value);

		if (CheckStatesForSpecificState("Slowed"))
		{
			SpeedMultiplier = SpeedMultiplier / 2;
		}

		// add movement in that direction
		AddMovementInput(Direction, Value*SpeedMultiplier);
		if (GEngine)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue,FString::Printf(TEXT("Direction %f"), Direction.Y));
		}
	}
}

void ANdorphinCharacter::SetDirection(float direction)
{
	FRotator rotation = GetActorRotation();
	if (direction > 0.0f)
	{
		rotation.Yaw = 90.0f;
	}
	else if (direction < 0.0f)
	{
		rotation.Yaw = -90.0f;
	}

	SetActorRotation(rotation);
}

bool ANdorphinCharacter::CheckStatesForSpecificState(FString toFind)
{
	bool toReturn = false;



	return toReturn;
}

// Called every frame
void ANdorphinCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANdorphinCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAxis("MoveRight", this, &ANdorphinCharacter::Move);
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	//PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);


}

