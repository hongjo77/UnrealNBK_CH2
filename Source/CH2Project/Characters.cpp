#include "Characters.h"
#include "Shop.h"

Characters* Characters::Instance = nullptr;

Characters::Characters(const FString& InName)
    : Name(InName), Level(1), Health(100), MaxHealth(100), Attack(10), Experience(0), Gold(0) {
    UE_LOG(LogTemp, Log, TEXT("캐릭터 %s 생성 완료! 레벨: %d, 체력: %d, 공격력: %d"),
        *Name, Level, Health, Attack);
}

Characters* Characters::GetInstance(const FString& InName) {
    if (!Instance) Instance = new Characters(InName);
    return Instance;
}

FString Characters::GetName() const { return Name; }

void Characters::DisplayStatus() const {
    UE_LOG(LogTemp, Log, TEXT("이름: %s | 레벨: %d | 체력: %d/%d | 공격력: %d | 경험치: %d | 골드: %d"),
        *Name, Level, Health, MaxHealth, Attack, Experience, Gold);
}

void Characters::LevelUp() {
    if (Level >= 10) return;
    Experience -= 100;
    Level++;
    MaxHealth += Level * 20;
    Attack += Level * 5;
    Health = MaxHealth;
    UE_LOG(LogTemp, Log, TEXT("레벨업! 현재 레벨: %d | 체력: %d | 공격력: %d"), Level, MaxHealth, Attack);
}

void Characters::UseItem(int32 Index) {
    if (Index < 0 || Index >= Inventory.Num()) {
        UE_LOG(LogTemp, Warning, TEXT("잘못된 인덱스입니다."));
        return;
    }
    Inventory[Index]->Use(*this);
    Inventory.RemoveAt(Index);
}

void Characters::VisitShop() {
    Shop ShopInstance;
    ShopInstance.DisplayItems();
    // 실제 구매 로직은 Shop에서 처리
}

void Characters::ShowInventory() const {
    UE_LOG(LogTemp, Log, TEXT("--- 인벤토리 ---"));
    if (Inventory.Num() == 0) {
        UE_LOG(LogTemp, Log, TEXT(" (비어있음)"));
        return;
    }
    for (int32 i = 0; i < Inventory.Num(); ++i) {
        UE_LOG(LogTemp, Log, TEXT("%d. %s"), i + 1, *Inventory[i]->GetName());
    }
}

int32 Characters::GetHealth() const 
{ 
    return Health; 
}

void Characters::SetHealth(int32 NewHealth) 
{ 
    Health = NewHealth; 
}

int32 Characters::GetMaxHealth() const 
{ 
    return MaxHealth; 
}

int32 Characters::GetAttack() const 
{ 
    return Attack; 
}

void Characters::SetAttack(int32 NewAttack) 
{ 
    Attack = NewAttack; 
}

int32 Characters::GetLevel() const 
{ 
    return Level; 
}

void Characters::SetLevel(int32 NewLevel) 
{ 
    Level = NewLevel; 
}

int32 Characters::GetExperience() const 
{ 
    return Experience; 
}

void Characters::SetExperience(int32 NewExp) 
{ 
    Experience = NewExp; 
}

int32 Characters::GetGold() const 
{ 
    return Gold; 
}

void Characters::SetGold(int32 NewGold) 
{ 
    Gold = NewGold; 
}

TArray<Item*>& Characters::GetInventory()
{ 
    return Inventory; 
}
