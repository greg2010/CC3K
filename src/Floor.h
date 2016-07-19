//
//  Floor.hpp
//  cc3k
//
//  Created by YoY on 2016-07-18.
//  Copyright © 2016 YoY. All rights reserved.
//

#ifndef Floor_h
#define Floor_h

#include <stdio.h>
#include <vector>
#include <string>

class Subject;
class Player;
class TextDisplay;
class Floor {
    std::vector<std::vector <std::shared_ptr<Subject> > > floorMap;  // row < col>
    std::shared_ptr<Player> player;
    std::shared_ptr<TextDisplay> td;
public:
    void readLayout();
    Floor(Player* player);
    ~Floor();
    void notify(std::shared_ptr<Subject> s);
    void deleteSubject(std::shared_ptr<Subject> s);
    std::vector<std::shared_ptr<Subject> > adjacent(std::shared_ptr<Subject> s);
    bool move(std::string dir, std::shared_ptr<Subject> s);
};

#endif /* Floor_hpp */
