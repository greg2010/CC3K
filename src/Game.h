//
//  Game.h
//  cc3k
//
//  Created by YoY on 2016-07-17.
//  Copyright © 2016 YoY. All rights reserved.
//


#ifndef Game_h
#define Game_h

#include <memory>
#include <string>
#include <fstream>
#include <iostream>

class Player;
class Floor;
class Subject;
class TextDisplay;
class Game : public std::enable_shared_from_this<Game> {
    std::shared_ptr<Player> generatePlayer();
    int currFloor;
    std::shared_ptr<Floor> floor;
    std::shared_ptr<Player> player;
    std::string playerType;
    std::ifstream &file;
    int seed;
    std::shared_ptr<TextDisplay> td;
public:
    Game(std::ifstream &file, int seed);
    ~Game();
    std::shared_ptr<Floor> getCurrentFloor();
    void movePlayer (std::string dir);
    void generateNextFloor();
    void usePotion(std::string dir);
    void attack(std::string dir);
    void display(std::ostream & out = std::cout);
    void endGame(bool cond);
};

#endif /* Game_h */
