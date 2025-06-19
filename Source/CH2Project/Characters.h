#pragma once

#include "CoreMinimal.h"
#include "Item.h"

class Characters
{
private:
    static Characters* Instance;
    FString Name;
    int32 Level;
    int32 Health;
    int32 MaxHealth;
    int32 Attack;
    int32 Experience;
    int32 Gold;
    TArray<Item*> Inventory;

protected:
    Characters(const FString& InName);

public:
    static Characters* GetInstance(const FString& InName = TEXT(""));

    FString GetName() const;
    void DisplayStatus() const;
    void LevelUp();
    void UseItem(int32 Index);
    void VisitShop();
    void ShowInventory() const;

    int32 GetHealth() const;
    void SetHealth(int32 NewHealth);
    int32 GetMaxHealth() const;
    int32 GetAttack() const;
    void SetAttack(int32 NewAttack);
    int32 GetLevel() const;
    void SetLevel(int32 NewLevel);
    int32 GetExperience() const;
    void SetExperience(int32 NewExp);
    int32 GetGold() const;
    void SetGold(int32 NewGold);
    TArray<Item*>& GetInventory();
    
};
