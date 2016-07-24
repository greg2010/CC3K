//
//  Game.c
//  cc3k
//
//  Created by YoY on 2016-07-17.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "Game.h"
#include "Floor.h"
#include "Player.h"
#include "ConcreteHuman.h"
#include "ConcreteElf.h"
#include "ConcreteOrc.h"
#include "ConcreteDwarf.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

Game::Game(){
    shared_ptr<Player> player = generatePlayer();
    int currFloor = 1;
    shared_ptr<Floor> floor = make_shared<Floor>(player, currFloor, playerType);
}

Game::~Game(){
    //delete player;
    //delete floor;
}

shared_ptr<Player> Game::generatePlayer(){
    char playerInput;
    string input, playerType;
    getline(cin, input);
    pair<int, int> coord = {-1, -1};
    if (input.empty())  playerInput = 'h';
    switch (playerInput) {
        case 'h':
            playerType = "Human";
            return make_shared<ConcreteHuman>(coord);
            break;
        case 'e':
            playerType = "Elf";
            return make_shared<ConcreteElf>(coord);
            break;
        case 'd':
            playerType = "Dwarf";
            return make_shared<ConcreteDwarf>(coord);
            break;
        case 'o':
            playerType = "Orc";
            return make_shared<ConcreteOrc>(coord);
            break;
        default:
            playerType = "Human";
            return make_shared<ConcreteHuman>(coord);
    }
    return nullptr;
}

shared_ptr<Floor> Game::getCurrentFloor(){
    return this->floor;
}

bool Game::movePlayer(string dir)
{
    return floor->move(dir, player);
    
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
        shared_ptr<Floor> floor = make_shared<Floor>(player, currFloor, playerType);

    }
    
}
