#include "PotHP.h"
using namespace std;

PotHP::PotHP(std::pair<int,int> coords):Potion{coors}{}

void PotHP::taken(Player &p){
	p.interact(*this);
}

int PotHP::getAtk(){
	return 0;
}

int PotHP::getDef(){
	return 0;
}
