#pragma once

#include "CoreMinimal.h"
#include "Characters.h"
#include "Monster.h"
#include "BossMonster.h"

class GameManager
{
public:
    Monster* GenerateMonster(int32 Level);
    BossMonster* GenerateBossMonster(int32 Level);
    void Battle(Characters& Player, Monster& Enemy);
    void VisitShop(Characters& Player);
    void DisplayInventory(Characters& Player);
};
