// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScriptableWidget.generated.h"

/**
 * 
 */
UCLASS()
class UBSAN_PROJECT_API UScriptableWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScriptableWidget", meta = (BindWidget))
	class UTextBlock* MyTextBlock;

	// 글자 출력 속도 (초 단위)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScriptableWidget")
	float CharacterDisplayInterval = 0.2f;

	FString FullText;
	FString CurrentText;

	FTimerHandle TextDisplayTimer;

public:
	void SetText(FString text);
	void DisplayNextCharacter();
	
};
