#ifndef A05_SUBJECT_H
#define A05_SUBJECT_H

#include <memory>
#include <utility>
#include <vector>

class Observer;

enum class SubjectType {
    Player,
    Goblin,
    Vampire,
    Werewolf,
    Troll,
    Merchant,
    Dragon,
    Phoenix,
    RH,
    PH,
    BA,
    WA,
    BD,
    WD,
    Gold,
    Stairway,
    Wall,
    Bridge,
    Door,
    Cell
};


class Subject : public std::enable_shared_from_this<Subject> {
public:
    Subject (int x, int y);
    Subject(std::pair<int,int> coords);
    void notifyObservers();
    void attach (std::shared_ptr<Observer> observer);
    void detach (std::shared_ptr<Observer> observer);
    std::pair<int, int> getCoordinates();
    virtual bool walkable();
    virtual SubjectType getType() = 0;
    virtual bool isVisible();
    virtual void remove();
protected:
    std::pair<int,int> coords;
private:
    std::vector<std::shared_ptr<Observer>> observers;
    bool visible;
};

#endif //A05_SUBJECT_H
