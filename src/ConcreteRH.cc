#include "ConcreteRH.h"

ConcreteRH::ConcreteRH(std::pair<int,int>coords):PotHP{coords}{};

int ConcreteRH::getHP(){
	return value;
}
