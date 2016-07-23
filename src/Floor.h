//
//  Floor.h
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
enum class ObjectType {
    Wall_h,
    Wall_v,
    Door,
    Brige,
    Space,
    Cell
};
class Floor {
    std::vector<std::vector <std::shared_ptr<Subject> > > floorMap;  // row < col>
    std::shared_ptr<Player> player;
    std::shared_ptr<TextDisplay> td;
    std::map<pair<int, int>, ObjectType > content;
    std::vector<shared_ptr<Chamber> > chambers;
public:
    int currFloor;
    const int cols = 75, rows = 25;
    void readLayout(std::istream &in);
    Floor(std::shared_ptr<Player> player, int currFloor);
    ~Floor();
    void notify(std::shared_ptr<Subject> s);
    void deleteSubject(std::shared_ptr<Subject> s);
    std::vector<std::shared_ptr<Subject> > adjacent(std::shared_ptr<Subject> s);
    bool move(std::string dir, std::shared_ptr<Subject> s);
    bool searchInChambers(int row, int col);
    void createNewChamber(int row, int col);
    std::vector<std::shared_ptr<Chamber> > getChamber();
};

#endif /* Floor_h */
