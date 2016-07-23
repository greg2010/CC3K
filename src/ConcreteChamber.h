#ifndef A05_CHAMBER_H
#define A05_CHAMBER_H


#include <utility>
#include <vector>
#include "Layout.h"

class ConcreteChamber : public Layout {
public:
    ConcreteChamber() = default;
    void addCoord(std::pair<int,int> wallCoord);
    std::vector<std::pair<int,int>> getCoords();
    std::vector<std::pair<int,int>> getCellCoords();

private:
    std::vector<std::vector<std::pair<int,int>>> wallCoords;
};


#endif //A05_CHAMBER_H
