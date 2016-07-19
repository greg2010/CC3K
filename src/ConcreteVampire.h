#ifndef A05_CONCRETEVAMPIRE_H
#define A05_CONCRETEVAMPIRE_H

#include "Enemy.h"

const int defaultHP = 50;
const int defaultAtk = 25;
const int defaultDef = 25;

class ConcreteVampire : public Enemy {

    ConcreteVampire(std::pair<int,int> coords);

};


#endif //A05_CONCRETEVAMPIRE_H
