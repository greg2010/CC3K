#ifndef _ITEM_
#define _ITEM_
#include "Subject.h"

class Item: public Subject{

	public:
		Item(std::pair<int,int>coords);
};

#endif
