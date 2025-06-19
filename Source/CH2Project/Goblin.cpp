#include "Goblin.h"
#include "HealthPotion.h"

Goblin::Goblin(int32 Level)
    : Monster(TEXT("Goblin"), FMath::RandRange(Level * 20, Level * 30), FMath::RandRange(Level * 5, Level * 10)) {
}

void Goblin::TakeDamage(int32 Damage) {
    Health -= Damage;
    if (Health < 0) Health = 0;
    UE_LOG(LogTemp, Log, TEXT("Goblin�� %d�� ���ظ� �Ծ����ϴ�. ���� ü��: %d"), Damage, Health);
}

Item* Goblin::DropItem() {
    if (FMath::FRand() < 0.3f) {
        UE_LOG(LogTemp, Log, TEXT("Goblin�� ü�� ������ ����߽��ϴ�!"));
        return new HealthPotion();
    }
    return nullptr;
}
