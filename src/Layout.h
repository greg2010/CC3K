#ifndef Layout_h
#define Layout_h

#include <vector>

class Layout {
public:
    virtual void addCoord(std::pair<int,int> coord) = 0;
    virtual std::vector<std::pair<int,int>> getCoords() = 0;
};

#endif
