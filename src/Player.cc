#include "Player.h"
#include "Potion.h"

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


void Player::pushPotion(std::shared_ptr<Potion> pot) {
    if (potDec) {
        potDec->push(pot);
    } else {
        potDec = pot;
    }
}

void Player::interact(std::shared_ptr<ConcreteGoldStashNormal> item) {
    this->doInteract(item);
    item->remove();
}

void Player::interact(std::shared_ptr<ConcreteGoldStashGuarded> item) {
    if (!item->isGuardianAlive()) {
        this->doInteract(item);
        item->remove();
    }
}

void Player::interact(std::shared_ptr<Potion> item) {
    this->pushPotion(item);
}

void Player::interact(std::shared_ptr<PotHP> hpPot) {
    this->doInteract(hpPot);
}

void Player::interact(std::shared_ptr<ConcreteStairway> item) {
    // Maybe handle in Floor?
}

void Player::doInteract(std::shared_ptr<ConcreteGoldStashNormal> item) {
    this->addGold(item->getValue());
}

void Player::doInteract(std::shared_ptr<ConcreteGoldStashGuarded> item) {
    this->addGold(item->getValue());
}

void Player::doInteract(std::shared_ptr<PotHP> hpPot) {
    this->changeHP(hpPot->getHP);
}

void Player::assignCoords(std::pair<int, int> coords) {
    this->coords = coords;
    notifyObservers();
}

unsigned int Player::getPotAttack() {
    return potDec->getAtk();
}

unsigned int Player::getPotDefence() {
    potDec->getDef();
}

