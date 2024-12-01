// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorDirector.generated.h"

class UScriptableWidget;

/// <summary>
/// �ʵ忡 ��ġ�� ���͸� ĳ���ϰ�, ������ �̺�Ʈ���� ���͵��� �Լ��� ��� �ҷ��ִ� ����
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
	// �� �� ������ �̺�Ʈ���� �Ҹ� �Լ����� �����Ѵ�.

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
