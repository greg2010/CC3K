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
    Troll,
    Merchant,
    Dragon,
    Phoenix,
    Potion,
    Gold,
    Stairway,
};


class Subject {
public:
    Subject (int x, int y);
    Subject(std::pair<int,int> coords);
    void notifyObservers();
    void attach (std::shared_ptr<Observer> observer);
    void detach (std::shared_ptr<Observer> observer);
    std::pair<int, int> getCoordinates();
    virtual SubjectType getType() = 0;
    virtual bool isVisible();
    virtual void remove();
    virtual ~Subject() = default;
protected:
    std::pair<int,int> coords;
    std::shared_ptr<Observer> getController();
private:
    std::vector<std::shared_ptr<Observer>> observers;
    bool visible;
};

#endif //A05_SUBJECT_H
