#include "Monster.h"

Monster::Monster(const FString& InName, int32 InHealth, int32 InAttack)
    : Name(InName), Health(InHealth), Attack(InAttack) {
}

FString Monster::GetName() const { return Name; }
int32 Monster::GetHealth() const { return Health; }
int32 Monster::GetAttack() const { return Attack; }

void Monster::TakeDamage(int32 Damage)
{
    Health -= Damage;
    if (Health < 0)
    {
        Health = 0;
    }
    UE_LOG(LogTemp, Log, TEXT("%s이(가) %d의 피해를 입었습니다. 남은 체력: %d"), *Name, Damage, Health);
}

Item* Monster::DropItem() { return nullptr; }
