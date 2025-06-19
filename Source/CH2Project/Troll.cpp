#include "Troll.h"
#include "HealthPotion.h"

Troll::Troll(int32 Level)
    : Monster(TEXT("Troll"), FMath::RandRange(Level * 25, Level * 35), FMath::RandRange(Level * 7, Level * 13)) {
}

void Troll::TakeDamage(int32 Damage) {
    Health -= Damage;
    if (Health < 0) Health = 0;
    UE_LOG(LogTemp, Log, TEXT("Troll이 %d의 피해를 입었습니다. 남은 체력: %d"), Damage, Health);
}

Item* Troll::DropItem() {
    if (FMath::FRand() < 0.3f) {
        UE_LOG(LogTemp, Log, TEXT("Troll이 체력 포션을 드랍했습니다!"));
        return new HealthPotion();
    }
    return nullptr;
}
