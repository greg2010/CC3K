#include "ConcreteElf.h"

ConcreteElf::ConcreteElf(std::pair<int,int> coords) : Player{defaultHP, defaultAtk, defaultDef, coords} { }

void ConcreteElf::doInteract(std::shared_ptr<PotHP> hpPot) {
    this->changeHP(abs(hpPot->getHP));
}

unsigned int ConcreteElf::getAttack() {
    int potVal = Player::getAttack();
    return Character::getAttack() + abs(Player::getAttack());
}

unsigned int ConcreteElf::getDefence() {
    int potVal = Player::getDefence();
    return Character::getDefence() + abs(Player::getDefence());
}