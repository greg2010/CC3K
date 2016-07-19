#ifndef A05_CONCRETEORC_H
#define A05_CONCRETEORC_H


#include <Player.h>

const int defaultHP = 180;
const int defaultAtk = 30;
const int defaultDef = 25;

const double goldMultiplier = 1/2;

class ConcreteOrc : public Player {
public:
    ConcreteOrc(std::pair<int,int> coords);

    virtual void doInteract(std::shared_ptr<ConcreteGoldStashNormal> item);
    virtual void doInteract(std::shared_ptr<ConcreteGoldStashGuarded> item);
};


#endif //A05_CONCRETEORC_H
