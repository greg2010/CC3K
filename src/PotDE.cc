#include "Player.h"
#include "PotDE.h"

PotDE::PotDE(std::pair<int,int> coords):Potion{coords}{}

void PotDE::taken(Player &p){
	p.interact(*this);
}

int PotDE::getHP(){
	return 0;
}

int PotDE::getAtk(){
	return 0;
}
