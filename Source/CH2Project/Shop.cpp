#include "Shop.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

Shop::Shop() {
    Items.Add(new HealthPotion());
    Items.Add(new AttackBoost());
}

void Shop::DisplayItems() const {
    UE_LOG(LogTemp, Log, TEXT("--- ���� ��� ---"));
    for (int32 i = 0; i < Items.Num(); ++i) {
        UE_LOG(LogTemp, Log, TEXT("%d. %s"), i + 1, *Items[i]->GetName());
    }
}

void Shop::BuyItem(int32 Index, Characters& Player) {
    if (Index < 0 || Index >= Items.Num()) {
        UE_LOG(LogTemp, Warning, TEXT("�߸��� �ε����Դϴ�."));
        return;
    }
    int32 Price = (Index == 0) ? 15 : 20; // ����: ���� 15���, �ν�Ʈ 20���
    if (Player.GetGold() < Price) {
        UE_LOG(LogTemp, Warning, TEXT("��尡 �����մϴ�."));
        return;
    }
    Player.SetGold(Player.GetGold() - Price);
    Player.GetInventory().Add(Items[Index]);
    UE_LOG(LogTemp, Log, TEXT("%s��(��) �����߽��ϴ�."), *Items[Index]->GetName());
}

void Shop::SellItem(int32 Index, Characters& Player) {
    TArray<Item*>& Inventory = Player.GetInventory();
    if (Index < 0 || Index >= Inventory.Num()) {
        UE_LOG(LogTemp, Warning, TEXT("�߸��� �ε����Դϴ�."));
        return;
    }
    // ����: �Ǹ� �� 10��� ����
    Player.SetGold(Player.GetGold() + 10);
    UE_LOG(LogTemp, Log, TEXT("%s��(��) �Ǹ��߽��ϴ�. 10��带 �޾ҽ��ϴ�."), *Inventory[Index]->GetName());
    Inventory.RemoveAt(Index);
}
