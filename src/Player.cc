#include "Player.h"
#include "ConcreteRH.h"
#include "ConcretePH.h"

#include "ConcreteGoldStashNormal.h"
#include "ConcreteGoldStashGuarded.h"


SubjectType Player::getType() {
    return SubjectType::Player;
}

Player::Player(int HP, int atk, int def, std::pair<int,int> coords) : Character{HP, atk, def, coords}, potDec{nullptr} {

}

unsigned int Player::getAttack() {
    return potDec ? Character::getAttack() + this->getPotAttack() : Character::getAttack();
}

unsigned int Player::getDefence() {
    return potDec ? Character::getDefence() + this->getPotDefence() : Character::getDefence();
}


void Player::pushPotion(Potion &pot) {
    if (potDec) {
        potDec->push(pot);
    } else {
        potDec = std::static_pointer_cast<Potion>(pot.shared_from_this());
    }
}

void Player::interact(ConcreteGoldStashNormal &item) {
    this->doInteract(item);
    item.remove();
}

void Player::interact(ConcreteGoldStashGuarded &item) {
    if (!item.isGuardianAlive()) {
        this->doInteract(item);
        item.remove();
    }
}

void Player::interact(Potion &item) {
    this->pushPotion(item);
}

void Player::interact(PotHP &hpPot) {
    this->doInteract(hpPot);
}

void Player::interact(ConcreteStairway &item) {
    // Maybe handle in Floor?
}

void Player::doInteract(ConcreteGoldStashNormal &item) {
    this->addGold(item.getGoldValue());
}

void Player::doInteract(ConcreteGoldStashGuarded &item) {
    this->addGold(item.getGoldValue());
}

void Player::doInteract(PotHP &hpPot) {
    this->changeHP(hpPot.getHP());
}

void Player::assignCoords(std::pair<int, int> coords) {
    this->coords = coords;
    notifyObservers();
}

int Player::getPotAttack() {
    return potDec->getAtk();
}

int Player::getPotDefence() {
    return potDec->getDef();
}

void Player::resetPotions() {
    potDec = nullptr;
}

