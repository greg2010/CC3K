#ifndef _POTION_
#define _POTION_
#include "Item.h"

class Player;

class Potion: public Item{
	public:
		Potion();
		virtual void taken(Player &p) = 0;
		virtual int getHP() = 0;
		virtual int getAtk() = 0;
		virtual int getDef() = 0;
		SubjectType getType();

protected:
	std::shared_ptr<Potion> decPot;
};


#endif
