//
//  Game.c
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
    floor = shared_ptr<Floor>(player, currFloor);
}

Game::~Game(){
    //delete player;
    //delete floor;
}

Player * Game::generatePlayer(){
    char playerType;
    string input;
    getline(cin, input);
    if (input.empty())  playerType = 'h';
    switch (playerType) {
        case 'h':   return shared_ptr<Human>(make_pair(-1, -1));
            break;
        case 'e':   return shared_ptr<Elf>(make_pair(-1, -1));
            break;
        case 'd':   return shared_ptr<Dwarf>(make_pair(-1, -1));
            break;
        case 'o':   return shared_ptr<Orc>(make_pair(-1, -1));
            break;
        default:    return shared_ptr<Human>(make_pair(-1, -1));
    }
    return nullptr;
}

Floor* Game::getCurrentFloor(){
    return this->floor;
}

bool Game::movePlayer(string dir)
{
    Floor::move(dir, player);
    
//    pair<int, int> coor = player->getCoordinates();
//    int i = 0;  // assume vector<subject*> [0] starts from left most conor and moving right
//    
//    if (dir =="no"){
//        coor.second -= 1;
//        i = 1;
//    }
//    else if(dir == "so"){
//        coor.second += 1;
//        i = 5;
//    }
//    else if(dir == "ea"){
//        coor.first += 1;
//        i = 3;
//    }
//    else if(dir == "we"){
//        coor.first -= 1;
//        i = 7;
//    }
//    else if(dir == "ne"){
//        coor.first += 1;
//        coor.second -= 1;
//        i = 2;
//    }
//    else if(dir == "nw"){
//        coor.first -= 1;
//        coor.second -= 1;
//        i = 0;
//    }
//    else if(dir == "se"){
//        coor.first += 1;
//        coor.second += 1;
//        i = 4;
//    }
//    else if(dir == "sw"){
//        coor.first -= 1;
//        coor.second += 1;
//        i = 6;
//    }
//    
//    vector<std::shared_ptr<Subject> > adj = Floor::adjacent(player);
//    if (adj[i] != nullptr){
//        if (dir == "we" && adj[i] -> Subject::getType() ==
//            Stariway){
//            generateNextFloor();
//            return true;
//        }
//        else return false;
//    }
//    else{
//        player->coords = coor;
//        return true;
//    }
//    
//    return false;
}

void Game::generateNextFloor(){
    if (currFloor >= 5){
        cout << "You won" << endl;
    }
    else {
        currFloor++;
        //delete floor;
        floor = shared_ptr<Floor>(player, currFloor);
    }
    
}