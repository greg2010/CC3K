#ifndef _CGSG_
#define _CGSG_
#include "GoldStash"

class ConcreteGoldStashGuarded: public GoldStash{
	int value;
	bool free = false;
	void freeGold();

	public:
		bool const isGuardianAlive();
};

#endif
