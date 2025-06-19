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
        UE_LOG(LogTemp, Log, TEXT("보스 몬스터 %s 등장! 체력: %d, 공격력: %d"),
            *Enemy.GetName(), Enemy.GetHealth(), Enemy.GetAttack());
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("몬스터 %s 등장! 체력: %d, 공격력: %d"),
            *Enemy.GetName(), Enemy.GetHealth(), Enemy.GetAttack());
    }
    while (Player.GetHealth() > 0 && Enemy.GetHealth() > 0) {
        Enemy.TakeDamage(Player.GetAttack());
        UE_LOG(LogTemp, Log, TEXT("%s가 %s을(를) 공격합니다! %s 체력: %d"),
            *Player.GetName(), *Enemy.GetName(), *Enemy.GetName(), Enemy.GetHealth());
        if (Enemy.GetHealth() <= 0) {
            UE_LOG(LogTemp, Log, TEXT("%s 처치!"), *Enemy.GetName());
            if (Enemy.IsBoss())
            {
                UE_LOG(LogTemp, Log, TEXT("축하합니다! 보스 %s을(를) 처치하고 게임을 클리어했습니다!"), *Enemy.GetName());
            }
            int32 GoldReward = FMath::RandRange(10, 20);
            Player.SetExperience(Player.GetExperience() + 50);
            Player.SetGold(Player.GetGold() + GoldReward);
            UE_LOG(LogTemp, Log, TEXT("%s가 50 EXP와 %d 골드를 획득했습니다. 현재 EXP: %d/100, 골드: %d"),
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
        UE_LOG(LogTemp, Log, TEXT("%s이 %s를 공격합니다! %s 체력: %d%s"),
            *Enemy.GetName(), *Player.GetName(), *Player.GetName(),
            Player.GetHealth(),
            PrevHealth != Player.GetHealth() ? *FString::Printf(TEXT(" → %d"), Player.GetHealth()) : TEXT(""));
        if (Player.GetHealth() <= 0) {
            //UE_LOG(LogTemp, Log, TEXT("%s가 사망했습니다. 게임 오버!"), *Player.GetName());
            //오류
            break;
        }
    }
}

void GameManager::VisitShop(Characters& Player) {
    FString Input;
    UE_LOG(LogTemp, Log, TEXT("상점을 방문하시겠습니까? (Y/N): "));
    std::string StdInput;
    std::getline(std::cin, StdInput);
    Input = FString(StdInput.c_str());
    if (Input.Equals(TEXT("Y"), ESearchCase::IgnoreCase))
    {
        Shop ShopInstance;
        ShopInstance.DisplayItems();
        UE_LOG(LogTemp, Log, TEXT("골드: %d"), Player.GetGold());
        UE_LOG(LogTemp, Log, TEXT("구매할 아이템 번호를 선택하세요: "));
        int32 Choice = 0;
        std::cin >> Choice;
        ShopInstance.BuyItem(Choice - 1, Player);
    }
}

void GameManager::DisplayInventory(Characters& Player) {
    Player.ShowInventory();
}
