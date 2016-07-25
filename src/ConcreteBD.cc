#include "ConcreteBD.h"

ConcreteBD::ConcreteBD(std::pair<int,int> coords): PotDE{coords}{}

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
