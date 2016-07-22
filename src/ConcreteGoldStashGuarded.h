#ifndef _CGSG_
#define _CGSG_
#include "GoldStash"

class Player;

class ConcreteGoldStashGuarded: public GoldStash{
	int value;
	bool free = false;
	public:
		void freeGold();
		void taken(Player &p) override;
		bool const isGuardianAlive();
};

#endif
