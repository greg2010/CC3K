#include "PotDE.h"

void PotDE::taken(Player &p){
	p.interact(*this);
}

int PotDE::getHP(){
	return 0;
}

int PotDE::getAtk(){
	return 0;
}
