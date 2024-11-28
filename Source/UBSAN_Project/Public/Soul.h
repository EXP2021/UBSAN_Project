// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Soul.generated.h"

/// <summary>
/// �⺻���� ��ȥ�� �����Ѵ�.
/// 1. �⺻������ OverLap�� �����ϴ� �浹�� �����ϴ�.
/// 2. ������ �������Ʈ�� �����Ѵ�.
/// 3. ��ȣ�ۿ� ������ ������Ʈ�� ������.
/// 4. ����Ʈ ���� ������ ������Ʈ�� ������.
/// </summary>
UCLASS()
class UBSAN_PROJECT_API ASoul : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASoul();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
