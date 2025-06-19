#include "BossMonster.h"
#include "AttackBoost.h"

BossMonster::BossMonster(int32 Level)
    : Monster(TEXT("Dragon"), 400 + Level * 5, 40 + Level * 2) {
}

void BossMonster::TakeDamage(int32 Damage) {
    Health -= Damage;
    if (Health < 0) Health = 0;
    UE_LOG(LogTemp, Log, TEXT("Dragon이 %d의 피해를 입었습니다. 남은 체력: %d"), Damage, Health);
}

Item* BossMonster::DropItem() {
    UE_LOG(LogTemp, Log, TEXT("Dragon이 공격력 부스트를 드랍했습니다!"));
    return new AttackBoost();
}
