#include "Cell.h"

Cell::Cell(std::pair<int, int> coords) : Subject{coords}, element{nullptr} { }

std::shared_ptr<Subject> &Cell::operator->() {
    return element;
}

Cell &Cell::operator=(std::shared_ptr<Subject> &rhs) {
    element = rhs;
    return *this;
}

Cell &Cell::operator=(std::shared_ptr<Subject> &&rhs) {
    element = rhs;
    return *this;
}

Cell::Cell(Cell &rhs) : Subject{rhs.getCoordinates()} { }

Cell::Cell(Cell &&rhs) : Subject{rhs.getCoordinates()} { }
