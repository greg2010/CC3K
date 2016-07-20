//
// Created by greg2010 on 18/07/16.
//

#ifndef A05_CONCRETEGOBLIN_H
#define A05_CONCRETEGOBLIN_H

#include "Enemy.h"

const int defaultHP = 70;
const int defaultAtk = 5;
const int defaultDef = 10;

class ConcreteGoblin : public Enemy {

    ConcreteGoblin(std::pair<int,int> coords);

};


#endif //A05_CONCRETEGOBLIN_H