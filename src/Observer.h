#ifndef A05_OBSERVER_H
#define A05_OBSERVER_H

class Subject;

enum class ObserverType {
    Controller,
    View
};

class Observer {
public:
    virtual void notify(Subject &s) = 0;
    virtual ObserverType obsType() = 0;
    virtual ~Observer() = default;
};


#endif //A05_OBSERVER_H
