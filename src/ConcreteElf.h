#ifndef A05_CONCRETEELF_H
#define A05_CONCRETEELF_H


#include <Player.h>

class ConcreteElf : public Player {
public:
    ConcreteElf(std::pair<int,int> coords);

    virtual unsigned int getAttack();
    virtual unsigned int getDefence();

protected:
    virtual void doInteract(PotHP &hpPot);
};


#endif //A05_CONCRETEELF_H
