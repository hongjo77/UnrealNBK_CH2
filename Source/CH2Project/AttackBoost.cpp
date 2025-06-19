#include "AttackBoost.h"
#include "Characters.h"

AttackBoost::AttackBoost() : Item(TEXT("Attack Boost")) {}

FString AttackBoost::GetName() const { return Name; }

void AttackBoost::Use(Characters& TargetCharacters) {
    TargetCharacters.SetAttack(TargetCharacters.GetAttack() + 10);
    UE_LOG(LogTemp, Log, TEXT("공격력이 10만큼 증가하였습니다! 현재 공격력: %d"), TargetCharacters.GetAttack());
}