#include "ConcreteGoldStashNormal.h"

void ConcreteGoldStashNormal::taken(Player &p){
	p.interact(*this);
}

int ConcreteGoldStashNormal::getGoldValue(){
	return value;
}
