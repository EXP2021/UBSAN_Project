// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorDirector.h"
#include "ScriptableWidget.h"

// Sets default values
AActorDirector::AActorDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorDirector::BeginPlay()
{
	Super::BeginPlay();
	
	OpenCrossArmWidget();
}

// Called every frame
void AActorDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorDirector::SpawnStoneTowerEffect(int index)
{
	if (StoneTowers.Num() <= index)
		return;

	if (ParticleActorClass)
	{
		auto& TargetStoneTower = StoneTowers[index];

		auto ActorLocation = TargetStoneTower->GetActorLocation();
		auto ActorRotation = TargetStoneTower->GetActorRotation();

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = TargetStoneTower; // 이 액터를 소환한 주체로 설정
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		// 액터 소환
		SpawnedParticleActor = GetWorld()->SpawnActor<AActor>(
			ParticleActorClass,
			ActorLocation,
			ActorRotation,
			SpawnParams
		);

		if (SpawnedParticleActor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Actor spawned at location: %s"), *ActorLocation.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to spawn actor at location: %s"), *ActorLocation.ToString());
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ActorToSpawn is not set!"));
	}

}

void AActorDirector::DestroyStoneTowerEffect()
{
	if (SpawnedParticleActor)
	{
		SpawnedParticleActor->Destroy();
	}

}

void AActorDirector::OpenScriptableWidget()
{
	if (ScriptableWidgetClass != nullptr)
	{
		ScriptableWidget = CreateWidget<UScriptableWidget>(GetWorld(), ScriptableWidgetClass);
		if (ScriptableWidget)
		{
			ScriptableWidget->AddToViewport();
		}
	}
}

void AActorDirector::CloseScriptableWidget()
{
	if (ScriptableWidgetClass != nullptr)
	{
		ScriptableWidget->RemoveFromParent();
	}
}

void AActorDirector::SetScriptContext(FString text)
{
	if (ScriptableWidgetClass != nullptr)
	{
		ScriptableWidget->SetText(text);
	}
}

void AActorDirector::OpenCrossArmWidget()
{
	if (CrossHairWidgetClass)
	{
		auto CrossHairWidget = CreateWidget<UUserWidget>(GetWorld(), CrossHairWidgetClass);
		if (CrossHairWidget)
		{
			CrossHairWidget->AddToViewport();
		}
	}
}

