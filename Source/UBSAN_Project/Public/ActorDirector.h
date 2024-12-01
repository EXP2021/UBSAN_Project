// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorDirector.generated.h"

class UScriptableWidget;

/// <summary>
/// 필드에 배치된 액터를 캐싱하고, 시퀀서 이벤트에서 액터들의 함수를 대신 불러주는 역할
/// </summary>
UCLASS()
class UBSAN_PROJECT_API AActorDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorDirector")
	TArray<AActor*> StoneTowers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorDirector")
	TSubclassOf<UScriptableWidget> ScriptableWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorDirector")
	TSubclassOf<AActor> ParticleActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorDirector")
	TSubclassOf<UUserWidget> CrossHairWidgetClass;

	UScriptableWidget* ScriptableWidget;
	AActor* SpawnedParticleActor;

public:
	// 이 곳 하위에 이벤트에서 불릴 함수들을 선언한다.

	UFUNCTION(BlueprintCallable, Category = "ActorDirector")
	void SpawnStoneTowerEffect(int index);

	UFUNCTION(BlueprintCallable, Category = "ActorDirector")
	void DestroyStoneTowerEffect();

	UFUNCTION(BlueprintCallable, Category = "ActorDirector")
	void OpenScriptableWidget();

	UFUNCTION(BlueprintCallable, Category = "ActorDirector")
	void CloseScriptableWidget();

	UFUNCTION(BlueprintCallable, Category = "ActorDirector")
	void SetScriptContext(const FString& text);

	void OpenCrossArmWidget();
};
