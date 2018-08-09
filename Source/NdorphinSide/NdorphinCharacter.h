// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NdorphinCharacter.generated.h"

UCLASS()
class NDORPHINSIDE_API ANdorphinCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANdorphinCharacter();

	//UPROPERTY(BlueprintReadWrite)
	float SpeedMultiplier = 1.0f;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void Move(float Value);

	UFUNCTION()
	void SetDirection(float direction);

	UFUNCTION()
	bool CheckStatesForSpecificState(FString toFind);

	UEnumProperty* ListOfStates;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
