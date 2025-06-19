#pragma once

#include "CoreMinimal.h"
#include "Monster.h"

class BossMonster : public Monster
{
public:
    BossMonster(int32 Level);
    void TakeDamage(int32 Damage) override;
    Item* DropItem() override;
    bool IsBoss() const override { return true; }
};
