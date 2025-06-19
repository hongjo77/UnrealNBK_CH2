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
    UE_LOG(LogTemp, Log, TEXT("%s��(��) %d�� ���ظ� �Ծ����ϴ�. ���� ü��: %d"), *Name, Damage, Health);
}

Item* Monster::DropItem() { return nullptr; }
