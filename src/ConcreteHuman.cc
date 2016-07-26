//
// Created by greg2010 on 18/07/16.
//

#include <cmath>
#include "ConcreteHuman.h"

ConcreteHuman::ConcreteHuman(std::pair<int,int> coords) : Player{defaultHP, defaultAtk, defaultDef, coords} { }

int ConcreteHuman::getScore() {
    return std::ceil(getGold() * 1.5);
}
