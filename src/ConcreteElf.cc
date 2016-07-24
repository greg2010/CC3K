#include <cstdlib>
#include "ConcreteElf.h"
#include "PotHP.h"

ConcreteElf::ConcreteElf(std::pair<int,int> coords) : Player{defaultHP, defaultAtk, defaultDef, coords} { }

void ConcreteElf::doInteract(PotHP &hpPot) {
    this->changeHP(abs(hpPot.getHP()));
}

unsigned int ConcreteElf::getAttack() {
    return Character::getAttack() + abs(this->getPotAttack());
}

unsigned int ConcreteElf::getDefence() {
    return Character::getDefence() + abs(this->getPotDefence());
}
