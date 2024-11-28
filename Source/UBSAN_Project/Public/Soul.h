// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Soul.generated.h"

/// <summary>
/// 기본적인 원혼을 정의한다.
/// 1. 기본적으로 OverLap을 감지하는 충돌이 가능하다.
/// 2. 외형은 블루프린트로 정의한다.
/// 3. 상호작용 가능한 컴포넌트를 가진다.
/// 4. 퀘스트 진행 가능한 컴포넌트를 가진다.
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
