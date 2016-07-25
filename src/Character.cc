#include <cmath>
#include <string>
#include "Character.h"

Character::Character(int HP, int atk, int def, std::pair<int,int> coords) : Subject{coords},
                                                                            HP{HP},
                                                                            atk{atk},
                                                                            def{def},
                                                                            gold{0},
                                                                            hasMovedThisTurn{false} { }

unsigned int Character::getHP() { return HP; }

unsigned int Character::getAttack() {
    return atk;
}

unsigned int Character::getDefence() {
    return def;
}

unsigned int Character::getGold() { return gold; }

void Character::move(std::pair<int,int> newCoords) {
    /*
    int ns = 0;
    int ew = 0;
    std::shared_ptr<Observer> controller = this->getController();
    std::vector<std::shared_ptr<Subject>> v = controller->adjacent(*this);
    if (dir.length() != 2) return false;
    if (dir == "no") {
        ++ns;
    } else if (dir == "so") {
        --ns;
    } else if (dir == "ea") {
        ++ew;
    } else if (dir == "we") {
        --ew;
    } else if (dir == "ne") {
        ++ns;
        ++ew;
    } else if (dir == "nw") {
        ++ns;
        --ew;
    } else if (dir == "se") {
        --ns;
        ++ew;
    } else if (dir == "sw") {
        --ns;
        --ew;
    }
    std::pair<int,int> curCoords = this->getCoordinates();
    std::pair<int,int> desiredCoords = std::make_pair(curCoords.first + ew, curCoords.second + ns);
    // TODO: check new coords (if needed)
    */
    this->coords = newCoords;
    this->notifyObservers();
}

int Character::attackedBy(std::shared_ptr<Character> attacker) {
    int damage = std::ceil((100/(100+this->getDefence())) * attacker->getAttack());
    this->changeHP(damage);
    this->notifyObservers();
    return damage;
}

bool Character::hasMoved() {
    return hasMovedThisTurn;
}

void Character::resetMove() {
    hasMovedThisTurn = false;
}

void Character::addGold(int val) {
    gold += val;
}

void Character::changeHP(int val) {
    int newHP = this->getHP() - val;
    if (newHP <= 0) {
        //TODO: death logic
    } else {
        this->HP = newHP;
    }
}




