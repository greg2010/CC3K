#ifndef A05_CONCRETEDWARF_H
#define A05_CONCRETEDWARF_H


#include <Player.h>

const int defaultHP = 100;
const int defaultAtk = 20;
const int defaultDef = 30;

const int goldMultiplier = 2;

class ConcreteDwarf : public Player {
public:
    ConcreteDwarf(std::pair<int,int> coords);

protected:
    virtual void doInteract(std::shared_ptr<ConcreteGoldStashNormal> item);
    virtual void doInteract(std::shared_ptr<ConcreteGoldStashGuarded> item);
};


#endif //A05_CONCRETEDWARF_H
