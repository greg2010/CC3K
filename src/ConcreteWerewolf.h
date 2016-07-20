#ifndef A05_CONCRETEWEREWOLF_H
#define A05_CONCRETEWEREWOLF_H

#include "Enemy.h"

const int defaultHP = 120;
const int defaultAtk = 30;
const int defaultDef = 5;

class ConcreteWerewolf : public Enemy {

    ConcreteWerewolf(std::pair<int,int> coords);

};


#endif //A05_CONCRETEWEREWOLF_H
