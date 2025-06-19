#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Characters.h"

class HealthPotion : public Item
{
public:
    HealthPotion();
    FString GetName() const override;
    void Use(Characters& TargetCharacters) override;
};
