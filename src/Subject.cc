#include "Observer.h"
#include "Subject.h"

Subject::Subject(int x, int y) : coords{std::make_pair(x,y)}, visible{true} { }

Subject::Subject(std::pair<int, int> coords) : coords{coords}, visible{true} { }

void Subject::attach(std::shared_ptr<Observer> observer) {
    for (auto ob : observers) {
        if (ob == observer) return;
    }
    observers.push_back(observer);
}

void Subject::detach(std::shared_ptr<Observer> observer) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            observers.erase(it);
        }
    }
}

std::pair<int, int> Subject::getCoordinates() {
    return coords;
}

bool Subject::isVisible() {
    return visible;
}

void Subject::remove() {
    visible = false;
    this->notifyObservers();
    std::vector<std::shared_ptr<Observer>> v = observers;
    for (auto ob : v) {
        this->detach(ob);
    }
}

void Subject::notifyObservers() {
    for (auto ob : observers) {
        ob->notify(shared_from_this());
    }
}
