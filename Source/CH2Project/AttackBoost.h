#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Characters.h"

class AttackBoost : public Item
{
public:
    AttackBoost();
    FString GetName() const override;
    void Use(Characters& TargetCharacters) override;
};
