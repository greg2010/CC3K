#include "ConcreteBD.h"

const int boostDef = 5;

ConcreteBD::ConcreteBD(std::pair<int,int> coords): PotDE{coords}, value {boostDef}{}

int ConcreteBD::getDef(){
	if (decPot){
		return value + decPot->getDef();
	} else {
		return value;
	}
}

SubjectType ConcreteBD::getType() {
    return SubjectType::BD;
}
