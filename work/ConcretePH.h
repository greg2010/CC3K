#ifndef _CONCRETEPH_
#define _CONCRETEPH_
#include "PotHP.h"

class ConcretePH: public PotHP{
	int value;
	public:
		int getHP() override;
};

#endif
