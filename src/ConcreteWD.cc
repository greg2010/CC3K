#include "ConcreteWD.h"

const int woundDef = -5;

ConcreteWD::ConcreteWD(std::pair<int,int>coords):PotDE{coords}, value{woundDef}{}

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
