#ifndef A05_CELL_H
#define A05_CELL_H


#include "Subject.h"

class Cell : public Subject {
public:
    Cell(std::pair<int,int> coords, ObjectType objType);
    Cell(Cell &rhs);
    Cell(Cell &&rhs);
    Cell &operator=(std::shared_ptr<Subject> &rhs);
    Cell &operator=(std::shared_ptr<Subject> &&rhs);
    std::shared_ptr<Subject> &operator->();
private:
    std::shared_ptr<Subject> element;
    ObjectType objType;
};

#endif //A05_CELL_H
