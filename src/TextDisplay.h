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
#include <memory>

class Item;
class Subject;
class Player;
class Observer;
enum class SubjectType;

class TextDisplay{
    std::map<SubjectType, char> charMap;
    std::vector<std::vector <char> > grid;
    std::string race;
public:
    int w, h, currFloor;
    std::shared_ptr<Player> pc;
    TextDisplay(std::shared_ptr<Player> pc, int currFloor, std::string race, int width = 75, int height = 25);
    ~TextDisplay();
    void notify(std::shared_ptr<Subject> sub, bool off);
    void notify(std::shared_ptr<Item> item, bool off);
    friend void operator<<(std::ostream &out, TextDisplay td);
    void drawLayout(std::istream &in);
};

#endif /* TextDisplay_h */
