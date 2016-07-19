#ifndef A05_CONCRETEHUMAN_H
#define A05_CONCRETEHUMAN_H


#include <Player.h>

const int defaultHP = 140;
const int defaultAtk = 20;
const int defaultDef = 20;

class ConcreteHuman : public Player {
public:
    ConcreteHuman(std::pair<int,int> coords);
};


#endif //A05_CONCRETEHUMAN_H
