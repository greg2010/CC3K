#ifndef A05_CONCRETEDWARF_H
#define A05_CONCRETEDWARF_H


#include "Player.h"

class ConcreteDwarf : public Player {
public:
    ConcreteDwarf(std::pair<int,int> coords);

protected:
    void doInteract(ConcreteGoldStashNormal &item) override;
    void doInteract(ConcreteGoldStashGuarded &item) override;
};


#endif //A05_CONCRETEDWARF_H
