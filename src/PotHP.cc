#include "Player.h"
#include "PotHP.h"
using namespace std;

PotHP::PotHP(std::pair<int,int> coords):Potion{coords}{}
void PotHP::taken(Player &p){
	p.interact(*this);
}

int PotHP::getAtk(){
	return 0;
}

int PotHP::getDef(){
	return 0;
}
