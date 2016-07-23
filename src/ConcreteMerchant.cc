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
    return false;
}

void ConcreteMerchant::attackedBy(std::shared_ptr<Character> attacker) {
    ConcreteMerchant::hostile = true;
    Character::attackedBy(attacker);
}





