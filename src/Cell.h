#ifndef A05_CELL_H
#define A05_CELL_H


#include "Subject.h"

class Cell : public Subject {
public:
    Cell(std::pair<int,int> coords);
    std::shared_ptr<Subject> &operator->() const;
private:
    std::shared_ptr<Subject> element;
};

#endif //A05_CELL_H
