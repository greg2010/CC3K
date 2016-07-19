#ifndef A05_CONCRETEPHOENIX_H
#define A05_CONCRETEPHOENIX_H


#include "Enemy.h"

const int defaultHP = 50;
const int defaultAtk = 35;
const int defaultDef = 20;

class ConcretePhoenix : public Enemy {

    ConcretePhoenix(std::pair<int,int> coords);

};


#endif //A05_CONCRETEPHOENIX_H