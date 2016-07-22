#include "ConcretePH.h"

ConcretePH::ConcretePH(std::pair<int, int>coords):PotHP{coords}{}

int ConcretePH::getHP(){
	return value;
}
