#include "Shop.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

Shop::Shop() {
    Items.Add(new HealthPotion());
    Items.Add(new AttackBoost());
}

void Shop::DisplayItems() const {
    UE_LOG(LogTemp, Log, TEXT("--- 상점 목록 ---"));
    for (int32 i = 0; i < Items.Num(); ++i) {
        UE_LOG(LogTemp, Log, TEXT("%d. %s"), i + 1, *Items[i]->GetName());
    }
}

void Shop::BuyItem(int32 Index, Characters& Player) {
    if (Index < 0 || Index >= Items.Num()) {
        UE_LOG(LogTemp, Warning, TEXT("잘못된 인덱스입니다."));
        return;
    }
    int32 Price = (Index == 0) ? 15 : 20; // 예시: 포션 15골드, 부스트 20골드
    if (Player.GetGold() < Price) {
        UE_LOG(LogTemp, Warning, TEXT("골드가 부족합니다."));
        return;
    }
    Player.SetGold(Player.GetGold() - Price);
    Player.GetInventory().Add(Items[Index]);
    UE_LOG(LogTemp, Log, TEXT("%s을(를) 구매했습니다."), *Items[Index]->GetName());
}

void Shop::SellItem(int32 Index, Characters& Player) {
    TArray<Item*>& Inventory = Player.GetInventory();
    if (Index < 0 || Index >= Inventory.Num()) {
        UE_LOG(LogTemp, Warning, TEXT("잘못된 인덱스입니다."));
        return;
    }
    // 예시: 판매 시 10골드 지급
    Player.SetGold(Player.GetGold() + 10);
    UE_LOG(LogTemp, Log, TEXT("%s을(를) 판매했습니다. 10골드를 받았습니다."), *Inventory[Index]->GetName());
    Inventory.RemoveAt(Index);
}
