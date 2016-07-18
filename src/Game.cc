//
//  Game.cpp
//  cc3k
//
//  Created by YoY on 2016-07-17.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "Game.h"
#include "Floor.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

Game::Game(){
    player = generatePlayer();
    currFloor = 1;
    floor = new Floor(player);
}

Game::~Game(){
    delete player;
    delete floor;
}

Player * Game::generatePlayer(){
    char playerType;
    string input;
    getline(cin, input);
    if (input.empty())  playerType = 'h';
    switch (playerType) {
        case 'h':   return shared_ptr<Human>;
            break;
        case 'e':   return new shared_ptr<Elf>;
            break;
        case 'd':   return new shared_ptr<Dwarf>;
            break;
        case 'o':   return new shared_ptr<Orc>;
            break;
        default:    return new shared_ptr<Human>;
    }
    return nullptr;
}

Floor* Game::getCurrentFloor(){
    return this->floor;
}

bool Game::movePlayer(string dir)
{
    
    pair<int, int> coor = player->getCoordinates();
    int i = 0;  // assume vector<subject*> [0] starts from left most conor and moving right
    
    if (dir =="no"){
        coor.second -= 1;
        i = 1;
    }
    else if(dir == "so"){
        coor.second += 1;
        i = 5;
    }
    else if(dir == "ea"){
        coor.first += 1;
        i = 3;
    }
    else if(dir == "we"){
        coor.first -= 1;
        i = 7;
    }
    else if(dir == "ne"){
        coor.first += 1;
        coor.second -= 1;
        i = 2;
    }
    else if(dir == "nw"){
        coor.first -= 1;
        coor.second -= 1;
        i = 0;
    }
    else if(dir == "se"){
        coor.first += 1;
        coor.second += 1;
        i = 4;
    }
    else if(dir == "sw"){
        coor.first -= 1;
        coor.second += 1;
        i = 6;
    }
    
    vector<Subject *> adj = Floor::adjacent(player);
    if (adj[i] != nullptr){
        if (dir == "we" && adj[i] -> getType() ==
            Stariway){
            Game :: generateNextFloor();
            return true;
        }
        else return false;
    }
    else{
        player->coords = coor;
        return true;
    }
    
    return false;
}

void generateNextFloor(){
    if (currFloor >= 5){
        cout << "You won" << endl;
    }
    else {
        currFloor++;
        delete floor;
        floor = new Floor(player*);
    }
    
}