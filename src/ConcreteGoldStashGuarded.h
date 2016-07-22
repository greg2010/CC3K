#ifndef _CGSG_
#define _CGSG_
#include "GoldStash.h"

class Player;

class ConcreteGoldStashGuarded: public GoldStash{
	int value;
	bool free = false;
	public:
		void freeGold();
		void taken(Player &p) override;
		bool const isGuardianAlive();
		int getGoldValue();
};

#endif
