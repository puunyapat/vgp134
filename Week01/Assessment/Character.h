#pragma once
#include <string>

namespace Game
{
	
	class Character
	{
		static bool quickTest;
		friend class GameEngine;

		public:
			Character();
			Character(std::string name, int att, int def, int hlt);

			void SetStats();
			void PrintStat();
			void TakeDamage(int dmg);

		private:
			void AddXP(int round);
			void IncreaseStat(int stat);

			std::string _name;
			int _xp;
			int _att;
			int _def;
			int _hlt;
			int _lvl;
	};
}

