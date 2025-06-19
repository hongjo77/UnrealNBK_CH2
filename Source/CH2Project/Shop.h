#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Characters.h"

class Shop
{
public:
    TArray<Item*> Items;

    Shop();
    void DisplayItems() const;
    void BuyItem(int32 Index, Characters& Player);
    void SellItem(int32 Index, Characters& Player);
};
