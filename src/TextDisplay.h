//
//  TextDisplay.h
//  cc3k
//
//  Created by YoY on 2016-07-18.
//  Copyright © 2016 YoY. All rights reserved.
//

#ifndef TextDisplay_h
#define TextDisplay_h

#include <iostream>
#include <map>
#include <vector>

#include "Observer.h"

class Item;
class Subject;
class Player;
class Observer;
enum class SubjectType;

class TextDisplay : public Observer {
    std::map<SubjectType, char> charMap;
    std::vector<std::vector <char> > grid;
    std::string race;
    std::string message;
    std::string potionMessage(std::shared_ptr<Subject> sub);
    std::string attackMessage(std::shared_ptr<Subject> attacker, std::shared_ptr<Subject> beingAttacked, int damage);
    int messageCounter;
public:
    int w, h, currFloor;
    std::shared_ptr<Player> pc;
    TextDisplay(std::shared_ptr<Player> pc, int currFloor, std::string race, int width = 75, int height = 25);
    ~TextDisplay() override;
    void notify(std::shared_ptr<Subject> sub, bool off) override;
    void notify(std::shared_ptr<Item> item, bool off);
    friend void operator<<(std::ostream &out, const TextDisplay &td);
    void drawLayout(std::istream &in);
    void finishTurn();
};

#endif /* TextDisplay_h */
