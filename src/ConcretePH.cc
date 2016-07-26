#include "ConcretePH.h"

const int decreaseHealth = -10;

ConcretePH::ConcretePH(std::pair<int, int>coords):PotHP{coords}, value{decreaseHealth}{}

int ConcretePH::getHP(){
	return value;
}

SubjectType ConcretePH::getType() {
    return SubjectType::PH;
}
