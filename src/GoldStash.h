#ifndef _GOLDSTASH_
#define _GOLDSTASH_
#include "Item.h"

class Player;

class GoldStash: public Item{

	public:
		GoldStash(std::pair<int,int>coords);
		void taken (Player &p);
		virtual void doTaken(Player &p) = 0;
		SubjectType getType();
        bool walkable();
};
#endif
