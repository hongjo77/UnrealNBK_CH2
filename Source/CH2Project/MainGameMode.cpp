#include "MainGameMode.h"
#include "Characters.h"
#include "GameManager.h"
#include <iostream>
#include <string>

void AMainGameMode::StartPlay()
{
    Super::StartPlay();

    // 1. 캐릭터 이름 입력받기
    std::string StdName;
    std::cout << "캐릭터 이름을 입력하세요: ";
    std::getline(std::cin, StdName);
    FString Name(StdName.c_str());

    Characters* Player = Characters::GetInstance(Name);
    Player->DisplayStatus();

    // 2. GameManager 생성 및 게임 루프 시작
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

    UE_LOG(LogTemp, Log, TEXT("게임이 종료되었습니다."));
}
