#ifndef _POTION_
#define _POTION_
#include "Item.h"

class Potion: public Item{
	Potion * decPot;

	public:
		Potion();
		virtual int getHP() = 0;
		virtual int getAtk() = 0;
		virtual int getDef() = 0;
		SubjectType getType();
		
};


#endif
