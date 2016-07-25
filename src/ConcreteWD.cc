#include "ConcreteWD.h"

ConcreteWD::ConcreteWD(std::pair<int,int>coords):PotDE{coords}{}

int ConcreteWD::getDef(){
	if (decPot){
		return value + decPot->getDef();
	} else {
		return value;
	}
}

SubjectType ConcreteWD::getType() {
    return SubjectType::WD;
}
