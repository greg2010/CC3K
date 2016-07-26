#include "ConcreteMerchant.h"


const int defaultHP = 30;
const int defaultAtk = 70;
const int defaultDef = 5;

bool ConcreteMerchant::hostile = false;

ConcreteMerchant::ConcreteMerchant(std::pair<int,int> coords) : Enemy{defaultHP, defaultAtk, defaultDef, coords} { }

bool ConcreteMerchant::isHostile() {
    return hostile;
}

bool ConcreteMerchant::isMoving() {
    return true;
}

int ConcreteMerchant::attackedBy(std::shared_ptr<Character> attacker) {
    ConcreteMerchant::hostile = true;
    return Character::attackedBy(attacker);
}

SubjectType ConcreteMerchant::getType(){
	return SubjectType::Merchant;
}



