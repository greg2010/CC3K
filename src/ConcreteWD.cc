#include "ConcreteWD.h"

int ConreteWE::getDef(){
	if (decPot){
		return value + decPot->getDef();
	} else {
		return value;
	}
}
