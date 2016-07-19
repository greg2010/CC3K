//
//  Floor.cpp
//  cc3k
//
//  Created by YoY on 2016-07-18.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "Floor.h"
#include "Generator.h"
#include "TextDisplay.h"
#include "Game.h"
#include <vector>

using namespace std;

Floor::Floor(Player *pc) : player(player) {
    Generator::generate();
}

Floor::~Floor() {
    for (int row = 0; row < 25; row++) {
        for (int col = 0; col < 79; col++) {
            deleteSubject(floorMap[row][col]);
        }
    }
}

void Floor::readLayout(){
    //TextDisplay::drawLayout();
}

void Floor::notify(std::shared_ptr<Subject> s){
    td->notify(s);
}


void Floor::deleteSubject(std::shared_ptr<Subject> s) {
    s->Subject::remove(();
}

vector<std::shared_ptr<Subject> > Floor::adjacent(std::shared_ptr<Subject> s) {
    pair<int, int> coor = s->getCoordinates();
    vector<std::shared_ptr<Subject> > neighbors;
    neighbors[0] = floorMap[coor.second - 1][coor.first - 1];
    neighbors[1] = floorMap[coor.second - 1][coor.first];
    neighbors[2] = floorMap[coor.second - 1][coor.first + 1];
    neighbors[3] = floorMap[coor.second][coor.first + 1];
    neighbors[4] = floorMap[coor.second + 1][coor.first + 1];
    neighbors[5] = floorMap[coor.second + 1][coor.first];
    neighbors[6] = floorMap[coor.second + 1][coor.first - 1];
    neighbors[7] = floorMap[coor.second][coor.first - 1];
    
    return neighbors;
}

bool Floor::move(string dir, std::shared_ptr<Subject> s){
    // it might be better if move receives set of coods instead of dir
    vector<std::shared_ptr<Subject> > neighbors = adjacent(s);
    pair<int, int> coor = s->getCoordinates();
    if(s->getType != SubjectType::Player){
        if (neighbors[3] == nullptr) {
            Character::move(dir, s);
            return true;
        }
        else if (neighbors[3] == Wall) { // we need to add wall to SubjectType?
            if(floorMap[s.coords.first + 1][0] == nullptr){
                Character::move(dir, s);
                return true;
            }
            else return false;
        }
    }
    else {
        if (dir =="no"){
            i = 1;
        }
        else if(dir == "so"){
            i = 5;
        }
        else if(dir == "ea"){
            i = 3;
        }
        else if(dir == "we"){
            i = 7;
        }
        else if(dir == "ne"){
            i = 2;
        }
        else if(dir == "nw"){
            i = 0;
        }
        else if(dir == "se"){
            i = 4;
        }
        else if(dir == "sw"){
            i = 6;
        }
        
        if (neighbors[i] != nullptr){
            if (dir == "we" && neighbors[i] -> Subject::getType() ==
                Stariway){
                Game::generateNextFloor();
                return true;
            }
            else return false;
        }
        else{
            Character::move(dir, s);
            return true;
        }
        
        return false;

    }
}













