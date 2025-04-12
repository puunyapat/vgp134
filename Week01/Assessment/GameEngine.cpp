#include "GameEngine.h"
#include "Character.h"
#include <iostream>

using namespace Game;

void GameEngine::Run()
{
    Character blue("blue", 7, 3, 5);
    blue.SetStats();
    blue.PrintStat();

    Character red("red", 7, 3, 5);
    red.SetStats();
    red.PrintStat();

    while (true)
    {
        int blueDamage = blue._att - red._def;
        int redDamage = red._att - blue._def;

        std::cout << "Blue attack Red with " << blueDamage << " damage.\n";
        red.TakeDamage(blueDamage);
        std::cout << "Red has " << red._hlt << " health left.\n\n";

        if (red._hlt <= 0)
        {
            std::cout << "Blue wins with " << blue._hlt << " health left.\n";
            break;
        }

        std::cout << "Red attack Blue with " << redDamage << " damage.\n";
        blue.TakeDamage(blueDamage);
        std::cout << "Blue has " << blue._hlt << " health left.\n\n";

        if (blue._hlt <= 0)
        {
            std::cout << "Red wins with " << red._hlt << " health left.\n";
            break;
        }

        system("pause");
    }
}