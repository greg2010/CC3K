#include "Player.h"
#include "PotAT.h"
using namespace std;

PotAT::PotAT(std::pair<int,int> coords):Potion{coords}{}

void PotAT::doTaken(Player &p){
	p.interact(*this);
}

int PotAT::getHP(){
	return 0;
}

int PotAT::getDef(){
	return 0;
}
