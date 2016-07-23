#ifndef A05_CONCRETEDWARF_H
#define A05_CONCRETEDWARF_H


#include "Player.h"

class ConcreteDwarf : public Player {
public:
    ConcreteDwarf(std::pair<int,int> coords);

protected:
    virtual void doInteract(ConcreteGoldStashNormal &item);
    virtual void doInteract(ConcreteGoldStashGuarded &item);
};


#endif //A05_CONCRETEDWARF_H
