#ifndef _STAIRWAY_
#define _STAIRWAY_
#include "Item.h"

class ConcreteStairway: public Item{
	
	public:
	ConcreteStairway(std::pair<int, int> coords);

	SubjectType getType();
        bool walkable();
};

#endif
