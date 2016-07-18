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

class Floor {
    std::vector<std::vector <Subject*> > floorMap;
public:
    void readLayout();
    Floor(Player* player);
    void notify(Subject* sub);
    void deleteSubject(Subject* sub);
    std::vector<Subject* > adjacent(Subject * sub);
    bool move(std::string dir);
};

#endif /* Floor_hpp */
