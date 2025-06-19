#pragma once

#include "CoreMinimal.h"
#include "Monster.h"

class Troll : public Monster
{
public:
    Troll(int32 Level);
    void TakeDamage(int32 Damage) override;
    Item* DropItem() override;
};
