#include "AttackBoost.h"
#include "Characters.h"

AttackBoost::AttackBoost() : Item(TEXT("Attack Boost")) {}

FString AttackBoost::GetName() const { return Name; }

void AttackBoost::Use(Characters& TargetCharacters) {
    TargetCharacters.SetAttack(TargetCharacters.GetAttack() + 10);
    UE_LOG(LogTemp, Log, TEXT("���ݷ��� 10��ŭ �����Ͽ����ϴ�! ���� ���ݷ�: %d"), TargetCharacters.GetAttack());
}