#ifndef _CGSG_
#define _CGSG_
#include "GoldStash"

class ConcreteGoldStashGuarded: public GoldStash{
	int value;
	bool free = false;
	public:
		void freeGold();
		bool const isGuardianAlive();
};

#endif
