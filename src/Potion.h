#ifndef _POTION_
#define _POTION_
#include "Item.h"

class Player;

class Potion: public Item {
	public:
		
		Potion(std::pair<int,int>coords);
		void taken(Player &p);
		virtual void doTaken(Player &p) = 0;
		virtual int getHP() = 0;
		virtual int getAtk() = 0;
		virtual int getDef() = 0;
		void push(Potion &other);
        bool walkable();

	protected:
		std::shared_ptr<Potion> decPot;
};


#endif
