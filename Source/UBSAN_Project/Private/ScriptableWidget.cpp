// Fill out your copyright notice in the Description page of Project Settings.


#include "ScriptableWidget.h"
#include "Components/TextBlock.h"

void UScriptableWidget::SetText(FString text)
{
    // �ʱ�ȭ
    CurrentText = TEXT("");
    FullText = text;

    if (MyTextBlock && !FullText.IsEmpty())
    {
        // Ÿ�̸� ����
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
    // ���� ��µ� ���� ��
    int32 CurrentLength = CurrentText.Len();

    // ���� ���ڰ� �ִٸ� �߰�
    if (CurrentLength < FullText.Len())
    {
        CurrentText.AppendChar(FullText[CurrentLength]);
        MyTextBlock->SetText(FText::FromString(CurrentText));
    }
    else
    {
        // ��� ���ڰ� ��µǸ� Ÿ�̸� ����
        GetWorld()->GetTimerManager().ClearTimer(TextDisplayTimer);
    }
}
