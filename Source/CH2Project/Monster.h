#pragma once

#include "CoreMinimal.h"
#include "Item.h"

class Monster
{
public:
    FString Name;
    int32 Health;
    int32 Attack;

    Monster(const FString& InName, int32 InHealth, int32 InAttack);
    virtual ~Monster() {}

    virtual FString GetName() const;
    virtual int32 GetHealth() const;
    virtual int32 GetAttack() const;
    virtual void TakeDamage(int32 Damage);
    virtual Item* DropItem();
    virtual bool IsBoss() const { return false; }
};
