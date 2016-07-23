#ifndef A05_CONCRETEORC_H
#define A05_CONCRETEORC_H


#include <Player.h>

class ConcreteOrc : public Player {
public:
    ConcreteOrc(std::pair<int,int> coords);

    virtual void doInteract(ConcreteGoldStashNormal &item);
    virtual void doInteract(ConcreteGoldStashGuarded &item);
};


#endif //A05_CONCRETEORC_H
