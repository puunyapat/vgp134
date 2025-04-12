#include "Character.h"
#include <iostream>
#include <cstdlib>

using namespace Game;

Character::Character()
	:_name(""), _xp(0), _att(0), _def(0), _hlt(1), _lvl(1)
{
}

Character::Character(std::string name, int att, int def, int hlt)
	:_name(name), _xp(0), _att(att), _def(def), _hlt(hlt), _lvl(1)
{
}

void Character::SetStats()
{
	int round;

	if (!quickTest)
	{
		std::cout << "Enter Character Name: ";
		std::cin >> _name;

		std::cout << "Enter Attack Value: ";
		std::cin >> _att;

		std::cout << "Enter Defense Value: ";
		std::cin >> _def;

		std::cout << "Enter Health Points: ";
		std::cin >> _hlt;
	}

	std::cout << "Enter total iteration for getting XP: ";
	std::cin >> round;

	AddXP(round);
}

void Character::PrintStat()
{
	std::cout << "\nName: " << _name << "\n";
	std::cout << "Level: " << _lvl << "\n";
	std::cout << "Experience: " << _xp << "\n";
	std::cout << std::string(20, '-') << "\n";

	std::cout << "Attack: " << _att << "\n";
	std::cout << "Defense: " << _def << "\n";
	std::cout << "Health: " << _hlt << "\n\n";
}

void Character::TakeDamage(int dmg)
{
	_hlt -= dmg;
	
	if (_hlt <= 0)
	{
		_hlt = 0;
	}
}

// leveling up
// 2 + 7 
// 2 % 5 = 2
// 5 - 2 = 3
// 2 + 3 >> +lvl
// 7 - 3 = 4

void Character::AddXP(int round)
{
	int randomXP, xpBaseOfCurrentLevel, xpToNextLevel, levelXP = 5, randomStat;

	std::srand((unsigned)time(NULL));

	for (int i = 0; i < round; i++)
	{
		randomXP = 2 + (rand() % 5);
		std::cout << _name << " get " << randomXP << " exp.\n";

		while (randomXP > 0) // fix this logic later
		{
			xpBaseOfCurrentLevel = _xp % levelXP;
			xpToNextLevel = levelXP - xpBaseOfCurrentLevel;
			_xp += xpToNextLevel;

			if (_xp > 5 && _xp % 5 == 0)
			{
				randomStat = rand() % 2;
				IncreaseStat(randomStat);
			}

			randomXP -= xpToNextLevel;
		}
	}
}

void Character::IncreaseStat(int stat)
{
	std::string statName;

	_lvl++;
	std::cout << "Your level has increased to " << _lvl << std::endl;

	switch (stat)
		{
		case 0:
		{
			statName = "Attack";
			_att += 3;
			break;
		}
		case 1:
		{
			statName = "Defense";
			_def += 3;
			break;
		}
		case 2:
		{
			statName = "Health";
			_hlt += 3;
			break;
		}
	}

	std::cout << "Your " << statName << " has increased by 3.\n";
}
