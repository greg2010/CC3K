#include "ConcreteWD.h"

int ConcreteWD::getDef(){
	if (decPot){
		return value + decPot->getDef();
	} else {
		return value;
	}
}
