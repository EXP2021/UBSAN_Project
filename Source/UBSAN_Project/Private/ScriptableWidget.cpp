// Fill out your copyright notice in the Description page of Project Settings.


#include "ScriptableWidget.h"
#include "Components/TextBlock.h"

void UScriptableWidget::SetText(FString text)
{
    // 초기화
    CurrentText = TEXT("");
    FullText = text;

    if (MyTextBlock && !FullText.IsEmpty())
    {
        // 타이머 시작
        GetWorld()->GetTimerManager().SetTimer(
            TextDisplayTimer,
            this,
            &UScriptableWidget::DisplayNextCharacter,
            CharacterDisplayInterval,
            true
        );
    }
}

void UScriptableWidget::DisplayNextCharacter()
{
    // 현재 출력된 글자 수
    int32 CurrentLength = CurrentText.Len();

    // 남은 글자가 있다면 추가
    if (CurrentLength < FullText.Len())
    {
        CurrentText.AppendChar(FullText[CurrentLength]);
        MyTextBlock->SetText(FText::FromString(CurrentText));
    }
    else
    {
        // 모든 글자가 출력되면 타이머 정지
        GetWorld()->GetTimerManager().ClearTimer(TextDisplayTimer);
    }
}
