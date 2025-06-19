#include "HealthPotion.h"
#include "Characters.h"

HealthPotion::HealthPotion() : Item(TEXT("Health Potion")) {}

FString HealthPotion::GetName() const { return Name; }

void HealthPotion::Use(Characters& TargetCharacters) {
    int32 NewHealth = TargetCharacters.GetHealth() + 50;
    if (NewHealth > TargetCharacters.GetMaxHealth())
        NewHealth = TargetCharacters.GetMaxHealth();
    TargetCharacters.SetHealth(NewHealth);
    UE_LOG(LogTemp, Log, TEXT("%s가 %s을 사용했습니다. %s 체력: %d"),
        *TargetCharacters.GetName(), *Name, *TargetCharacters.GetName(), TargetCharacters.GetHealth());
}
