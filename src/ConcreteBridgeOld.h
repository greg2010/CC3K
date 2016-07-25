#ifndef A05_CONCRETEBRIDGE_H
#define A05_CONCRETEBRIDGE_H


#include "Layout.h"

class ConcreteBridgeOld : public Layout {
public:
    ConcreteBridgeOld();
    void addCoord(std::pair<int,int> bridgeCoord);
    std::vector<std::pair<int,int>> getCoords();

private:
    std::vector<std::pair<int,int>> bridgeCoords;
    bool vertical;
};


#endif //A05_CONCRETEBRIDGE_H
