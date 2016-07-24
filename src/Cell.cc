#include "Cell.h"

Cell::Cell(std::pair<int, int> coords) : Subject{coords}, element{nullptr} { }

std::shared_ptr<Subject> &Cell::operator->() const {
    return element;
}
