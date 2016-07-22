#ifndef _CONCRETEPH_
#define _CONCRETEPH_
#include "PotHP.h"

class ConcretePH: public PotHP{
	int value;
	public:
		ConcretePH(std::pair<int,int> coords);
		int getHP() override;
};

#endif
