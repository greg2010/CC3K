#include "Cell.h"

Cell::Cell(std::pair<int,int>coords):Item{coords}{}

SubjectType Cell::getType() {
    return SubjectType::Cell;
}

bool Cell::walkable() {
    return true;
}
