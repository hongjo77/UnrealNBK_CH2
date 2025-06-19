#include "GameManager.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "Shop.h"
#include <iostream>
#include <string>

Monster* GameManager::GenerateMonster(int32 Level) {
    int32 Type = FMath::RandRange(0, 2);
    switch (Type)
    {
    case 0: return new Goblin(Level);
    case 1: return new Orc(Level);
    case 2: return new Troll(Level);
    default: return new Goblin(Level);
    }
}

BossMonster* GameManager::GenerateBossMonster(int32 Level) {
    return new BossMonster(Level);
}

void GameManager::Battle(Characters& Player, Monster& Enemy) {
    if (Enemy.IsBoss())
    {
        UE_LOG(LogTemp, Log, TEXT("���� ���� %s ����! ü��: %d, ���ݷ�: %d"),
            *Enemy.GetName(), Enemy.GetHealth(), Enemy.GetAttack());
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("���� %s ����! ü��: %d, ���ݷ�: %d"),
            *Enemy.GetName(), Enemy.GetHealth(), Enemy.GetAttack());
    }
    while (Player.GetHealth() > 0 && Enemy.GetHealth() > 0) {
        Enemy.TakeDamage(Player.GetAttack());
        UE_LOG(LogTemp, Log, TEXT("%s�� %s��(��) �����մϴ�! %s ü��: %d"),
            *Player.GetName(), *Enemy.GetName(), *Enemy.GetName(), Enemy.GetHealth());
        if (Enemy.GetHealth() <= 0) {
            UE_LOG(LogTemp, Log, TEXT("%s óġ!"), *Enemy.GetName());
            if (Enemy.IsBoss())
            {
                UE_LOG(LogTemp, Log, TEXT("�����մϴ�! ���� %s��(��) óġ�ϰ� ������ Ŭ�����߽��ϴ�!"), *Enemy.GetName());
            }
            int32 GoldReward = FMath::RandRange(10, 20);
            Player.SetExperience(Player.GetExperience() + 50);
            Player.SetGold(Player.GetGold() + GoldReward);
            UE_LOG(LogTemp, Log, TEXT("%s�� 50 EXP�� %d ��带 ȹ���߽��ϴ�. ���� EXP: %d/100, ���: %d"),
                *Player.GetName(), GoldReward, Player.GetExperience(), Player.GetGold());
            while (Player.GetExperience() >= 100 && Player.GetLevel() < 10) {
                Player.LevelUp();
            }
            break;
        }
        int32 PrevHealth = Player.GetHealth();
        int32 NewHealth = PrevHealth - Enemy.GetAttack();
        if (NewHealth < 0) NewHealth = 0;
        Player.SetHealth(NewHealth);
        UE_LOG(LogTemp, Log, TEXT("%s�� %s�� �����մϴ�! %s ü��: %d%s"),
            *Enemy.GetName(), *Player.GetName(), *Player.GetName(),
            Player.GetHealth(),
            PrevHealth != Player.GetHealth() ? *FString::Printf(TEXT(" �� %d"), Player.GetHealth()) : TEXT(""));
        if (Player.GetHealth() <= 0) {
            //UE_LOG(LogTemp, Log, TEXT("%s�� ����߽��ϴ�. ���� ����!"), *Player.GetName());
            //����
            break;
        }
    }
}

void GameManager::VisitShop(Characters& Player) {
    FString Input;
    UE_LOG(LogTemp, Log, TEXT("������ �湮�Ͻðڽ��ϱ�? (Y/N): "));
    std::string StdInput;
    std::getline(std::cin, StdInput);
    Input = FString(StdInput.c_str());
    if (Input.Equals(TEXT("Y"), ESearchCase::IgnoreCase))
    {
        Shop ShopInstance;
        ShopInstance.DisplayItems();
        UE_LOG(LogTemp, Log, TEXT("���: %d"), Player.GetGold());
        UE_LOG(LogTemp, Log, TEXT("������ ������ ��ȣ�� �����ϼ���: "));
        int32 Choice = 0;
        std::cin >> Choice;
        ShopInstance.BuyItem(Choice - 1, Player);
    }
}

void GameManager::DisplayInventory(Characters& Player) {
    Player.ShowInventory();
}
