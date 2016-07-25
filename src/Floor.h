//
//  Floor.h
//  cc3k
//
//  Created by YoY on 2016-07-18.
//  Copyright © 2016 YoY. All rights reserved.
//

#ifndef Floor_h
#define Floor_h

#include <map>
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include "Observer.h"
#include "Subject.h"
#include "TextDisplay.h"

class Subject;
class Player;
class TextDisplay;
class Observer;
class ConcreteChamber;
class Generator;
class Game;
enum class ObjectType {
    Wall_h,
    Wall_v,
    Door,
    Bridge,
    Space,
    Cell
};
class Floor : public Observer, public std::enable_shared_from_this<Floor>{
    std::vector<std::vector <std::shared_ptr<Subject> > > floorMap;  // row < col>
    std::shared_ptr<Player> player;
    std::shared_ptr<TextDisplay> td;
    std::map<std::pair<int, int>, ObjectType > content;
    std::vector<std::shared_ptr<ConcreteChamber> > chambers;
    int hp, atk, def, gold, seed;
    std::pair<int, int> coord;
    std::shared_ptr<Generator> gen;
    std::shared_ptr<Game> game;
    std::string playerType;
    std::fstream& file;
    void doAttack(std::shared_ptr<Subject> attacker);
    void doMove(std::shared_ptr<Subject> enemy);
public:
    int currFloor;
    const int cols = 79, rows = 25;
    void readLayout(std::istream &in);
    Floor(std::shared_ptr<Player> player, int currFloor, std::string playerType, std::fstream &file, int seed, std::shared_ptr<TextDisplay> td);
    ~Floor();
    void notify(std::shared_ptr<Subject> s, bool off = true);
    void deleteSubject(std::shared_ptr<Subject> s);
    std::vector<std::shared_ptr<Subject> > adjacent(std::shared_ptr<Subject> s);
    bool move(std::string dir, std::shared_ptr<Subject> s);
    bool searchInChambers(int row, int col);
    void createNewChamber(int row, int col);
    void usePotion(std::string dir);
    void attack(std::string dir);
    std::vector<std::shared_ptr<ConcreteChamber> > getChamber();
    void cutFile(std::fstream& file);
    void enemyTurn();
};

#endif /* Floor_h */
