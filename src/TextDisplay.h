//
//  TextDisplay.h
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

class TextDisplay{
    std::map<SubjectType, char> charMap;
    std::vector<std::vector <char> > grid;
    
public:
    int w, h;
    std::shared_ptr<Player> pc;
    TextDisplay(std::shared_ptr<Player> pc, int currFloor, int width = 75, int height = 25);
    ~TextDisplay();
    void notify(std::shared_ptr<Subject> sub, bool off);
    void notify(std::shared_ptr<Item> item, bool off);
    friend void operator<<(std::ostream &out, const TextDisplay td);
    void drawLayout(std::istream &in);
};

#endif /* TextDisplay_h */
