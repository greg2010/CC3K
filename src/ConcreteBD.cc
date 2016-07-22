#include "ConcreteBD.h"

int ConcreteBD::getDef(){
	if (decPot){
		return value + decPot->getDef();
	} else {
		return value;
	}
}
