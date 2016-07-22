#ifndef _GOLDSTASH_
#define _GOLDSTASH_
#include "Item.h"

class Player;

class GoldStash: public Item{

	public:
		virtual void taken(Player &p) = 0;
		SubjectType getType();
};
#endif
