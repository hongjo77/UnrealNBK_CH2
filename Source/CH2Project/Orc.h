#pragma once

#include "CoreMinimal.h"
#include "Monster.h"

class Orc : public Monster
{
public:
    Orc(int32 Level);
    void TakeDamage(int32 Damage) override;
    Item* DropItem() override;
};
