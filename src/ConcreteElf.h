#ifndef A05_CONCRETEELF_H
#define A05_CONCRETEELF_H


#include "Player.h"

class ConcreteElf : public Player {
public:
    ConcreteElf(std::pair<int,int> coords);

    unsigned int getAttack() override;
    unsigned int getDefence() override;

protected:
    virtual void doInteract(PotHP &hpPot);
};


#endif //A05_CONCRETEELF_H
