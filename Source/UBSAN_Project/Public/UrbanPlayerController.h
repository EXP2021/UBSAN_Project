// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UrbanPlayerController.generated.h"

/// <summary>
/// 인풋이 들어오면 게임을 진행시킨다.
/// 1. UI
/// 2. GameMode나 GameInstance의 정보를 갱신한다. 
/// </summary>
UCLASS()
class UBSAN_PROJECT_API AUrbanPlayerController : public APlayerController
{
	GENERATED_BODY()
	
};
