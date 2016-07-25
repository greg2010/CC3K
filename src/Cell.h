#ifndef A05_CELL_H
#define A05_CELL_H


#include "Subject.h"
#include "Item.h"

class Cell: public Item{

public:
    Cell(std::pair<int,int>coords);
    SubjectType getType();
    bool walkable();
};


#endif //A05_CELL_H
