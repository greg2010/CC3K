#include "PotAt.h"
using namespace std;

void PotAT::taken(Player &p){
	p.interact(*this);
}

int PotAT::getHP(){
	return 0;
}

int PotAT::getDef(){
	return 0;
}
