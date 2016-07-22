#include "ConcreteMerchant.h"

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





