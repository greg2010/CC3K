#ifndef A05_CONCRETEORC_H
#define A05_CONCRETEORC_H


#include "Player.h"

class ConcreteOrc : public Player {
public:
    ConcreteOrc(std::pair<int,int> coords);
protected:
    void doInteract(ConcreteGoldStashNormal &item) override;
    void doInteract(ConcreteGoldStashGuarded &item) override;
};


#endif //A05_CONCRETEORC_H
