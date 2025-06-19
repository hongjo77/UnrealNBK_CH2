#pragma once

#include "CoreMinimal.h"

class Characters; // Forward declaration

class Item
{
public:
    FString Name;
    Item(const FString& InName);
    virtual ~Item() {}
    virtual FString GetName() const;
    virtual void Use(Characters& TargetCharacters) = 0;
};
