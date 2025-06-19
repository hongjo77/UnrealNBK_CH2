#pragma once

#include "CoreMinimal.h"
#include "Monster.h"

class Goblin : public Monster
{
public:
    Goblin(int32 Level);
    void TakeDamage(int32 Damage) override;
    Item* DropItem() override;
};
