#include "MainGameMode.h"
#include "Characters.h"
#include "GameManager.h"
#include <iostream>
#include <string>

void AMainGameMode::StartPlay()
{
    Super::StartPlay();

    // 1. ĳ���� �̸� �Է¹ޱ�
    std::string StdName;
    std::cout << "ĳ���� �̸��� �Է��ϼ���: ";
    std::getline(std::cin, StdName);
    FString Name(StdName.c_str());

    Characters* Player = Characters::GetInstance(Name);
    Player->DisplayStatus();

    // 2. GameManager ���� �� ���� ���� ����
    GameManager Manager;
    while (Player->GetHealth() > 0 && Player->GetLevel() < 10)
    {
        Monster* Enemy = Manager.GenerateMonster(Player->GetLevel());
        Manager.Battle(*Player, *Enemy);
        delete Enemy;
        Manager.VisitShop(*Player);
    }

    if (Player->GetLevel() >= 10)
    {
        BossMonster* Boss = Manager.GenerateBossMonster(Player->GetLevel());
        Manager.Battle(*Player, *Boss);
        delete Boss;
    }

    UE_LOG(LogTemp, Log, TEXT("������ ����Ǿ����ϴ�."));
}
