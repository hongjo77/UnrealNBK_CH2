#include "BossMonster.h"
#include "AttackBoost.h"

BossMonster::BossMonster(int32 Level)
    : Monster(TEXT("Dragon"), 400 + Level * 5, 40 + Level * 2) {
}

void BossMonster::TakeDamage(int32 Damage) {
    Health -= Damage;
    if (Health < 0) Health = 0;
    UE_LOG(LogTemp, Log, TEXT("Dragon�� %d�� ���ظ� �Ծ����ϴ�. ���� ü��: %d"), Damage, Health);
}

Item* BossMonster::DropItem() {
    UE_LOG(LogTemp, Log, TEXT("Dragon�� ���ݷ� �ν�Ʈ�� ����߽��ϴ�!"));
    return new AttackBoost();
}
