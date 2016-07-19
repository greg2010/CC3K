//
//  TextDisplay.hpp
//  cc3k
//
//  Created by YoY on 2016-07-18.
//  Copyright © 2016 YoY. All rights reserved.
//

#ifndef TextDisplay_h
#define TextDisplay_h

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

class Item;
class Subject;
enum class SubjectType {
    Player,
    Vampire,
    Werewolf,
    Troll,
    Goblin,
    Dragon,
    Phoenix,
    Merchant,
    Stairway,
    Potion,
    Gold
};
class TextDisplay{
    std::map<SubjectType, char> charMap;
    std::vector<std::vector <char> > grid;
public:
    int w, h;
    TextDisplay(int width = 75, int height = 25);
    ~TextDisplay();
    void notify(std::shared_ptr<Subject> sub);
    void notify(std::shared_ptr<Item> item);
    friend void operator<<(std::ostream &out, const TextDisplay td);
    void drawLayout();
};

#endif /* TextDisplay_hpp */
