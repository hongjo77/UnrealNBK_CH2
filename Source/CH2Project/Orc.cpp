#include "Orc.h"
#include "AttackBoost.h"

Orc::Orc(int32 Level)
    : Monster(TEXT("Orc"), FMath::RandRange(Level * 22, Level * 32), FMath::RandRange(Level * 6, Level * 12)) {
}

void Orc::TakeDamage(int32 Damage) {
    Health -= Damage;
    if (Health < 0) Health = 0;
    UE_LOG(LogTemp, Log, TEXT("Orc가 %d의 피해를 입었습니다. 남은 체력: %d"), Damage, Health);
}

Item* Orc::DropItem() {
    if (FMath::FRand() < 0.3f) {
        UE_LOG(LogTemp, Log, TEXT("Orc가 공격력 부스트를 드랍했습니다!"));
        return new AttackBoost();
    }
    return nullptr;
}
