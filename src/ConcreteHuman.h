#ifndef A05_CONCRETEHUMAN_H
#define A05_CONCRETEHUMAN_H


#include <Player.h>

class ConcreteHuman : public Player {
public:
    ConcreteHuman(std::pair<int,int> coords);
};


#endif //A05_CONCRETEHUMAN_H
