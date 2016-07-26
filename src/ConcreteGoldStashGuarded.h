#ifndef _CGSG_
#define _CGSG_
#include "GoldStash.h"

class Player;

class ConcreteGoldStashGuarded: public GoldStash{
	int value;
	bool free = false;
	public:
		ConcreteGoldStashGuarded(std::pair<int,int> coords, int value);
		void freeGold();
		void doTaken(Player &p) override;
		bool const isGuardianAlive();
		int getGoldValue();
};

#endif
