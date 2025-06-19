#include "HealthPotion.h"
#include "Characters.h"

HealthPotion::HealthPotion() : Item(TEXT("Health Potion")) {}

FString HealthPotion::GetName() const { return Name; }

void HealthPotion::Use(Characters& TargetCharacters) {
    int32 NewHealth = TargetCharacters.GetHealth() + 50;
    if (NewHealth > TargetCharacters.GetMaxHealth())
        NewHealth = TargetCharacters.GetMaxHealth();
    TargetCharacters.SetHealth(NewHealth);
    UE_LOG(LogTemp, Log, TEXT("%s�� %s�� ����߽��ϴ�. %s ü��: %d"),
        *TargetCharacters.GetName(), *Name, *TargetCharacters.GetName(), TargetCharacters.GetHealth());
}
