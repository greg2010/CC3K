//
//  Floor.cc
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

Floor::Floor(std::shared_ptr<Player> pc, int currFloor) : player(player), currFloor(currFloor) {
    Generator::generate();
    TextDisplay::TextDisplay(player, currFloor);
}

Floor::~Floor() {}

void Floor::readLayout(istream &in){
    TextDisplay::drawLayout(in);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            char c;
            in >> std::noskipws >> c;
            
            switch (c) {
                case ' ':
                    floorMap[row][col] = nullptr; // not valid space for any object
                    content[row, col] = ObjectType::Space;
                    continue;
                case '|':
                    floorMap[row][col] = nullptr; // not valid space for any object
                    content[row, col] = ObjectType::Wall_v;
                    continue;
                case '-':
                    floorMap[row][col] = nullptr; // not valid space for any object
                    content[row, col] = ObjectType::Wall_h;
                    continue;
                case '.':
                    floorMap[row][col] = nullptr; // not valid space for any object
                    content[row, col] = ObjectType::Cell;
                    continue;
                case '+':
                    floorMap[row][col] = nullptr; // not valid space for any object
                    content[row, col] = ObjectType::Door;
                    continue;
                case '#':
                    floorMap[row][col] = nullptr; // not valid space for any object
                    content[row, col] = ObjectType::Brige;
                    continue;
                default: break;
            }
        }
    }
     //assume we can skip the outer layer of the game board INTIAL VALUE FOR COL, ROW = 2
  
    //the following code stores value of starting and ending point of walls in one chamber
    //need to be modified - finding the 5 left corners of 5 chambers find which case is the corner belongs to
    //the outmost condition is that endrow, endcol != originalrow, originalCol
    //bridge is not considered at all...
    
    
    vector<pair<pair<int, int>, pair<int, int> > > walls // begin<row, col> , end<row, col>
    //left-top corner |--  1
    //                |..
    content[row-1, col] = ObjectType::Space;
    content[row, col-1] = ObjectType::Space;
    content[row, col]   = ObjectType::Wall_v;
    content[row, col+1]   = ObjectType::Wall_h;
    content[row+1, col]   = ObjectType::Wall_v;
    
    // FIND this case
    int startRow = row, int startCol = col;
    endRow = startRow, endCol = startCol;
    while ((content[endRow, endCol+1] == ObjectType::Wall_h) || (content[endRow, endCol+1] == ObjectType::Brige)) {
        endCol++;
    }
    walls[i] = make_pair(make_pair(startRow, ++endCol), make_pair(endRow, ++endCol));
    
    //--|   -- 2
    //..|
    content[row-1, col] = ObjectType::Space;
    content[row, col-1] = ObjectType::Wall_h;
    content[row, col]   = ObjectType::Wall_v;
    content[row, col+1]   = ObjectType::Space;
    content[row+1, col]   = ObjectType::Wall_v;
    
    startRow = endRow, startCol = endCol;
    while ((content[endRow, endCol] == ObjectType::Wall_v) || (content[endRow, endCol+1] == ObjectType::Brige)) {
        endRow++;
    }
    walls[i] = make_pair(make_pair(startRow, startCol), make_pair(endRow, endCol));
    
    //..|   --3
    //--|
    content[row-1, col] = ObjectType::Wall_v;
    content[row, col-1] = ObjectType::Wall_h;
    content[row, col]   = ObjectType::Wall_v;
    content[row, col+1]   = ObjectType::Space;
    content[row+1, col]   = ObjectType::Space;
    
    startRow = endRow, startCol = endCol;
    while ((content[endRow, endCol-1] == ObjectType::Wall_h) || (content[endRow, endCol+1] == ObjectType::Brige)) {
        endCol--;
    }
    walls[i] = make_pair(make_pair(startRow, startCol), make_pair(endRow, --endCol));
    
    //|..   --4
    //|--
    content[row-1, col] = ObjectType::Wall_v;
    content[row, col-1] = ObjectType::Space;
    content[row, col]   = ObjectType::Wall_v;
    content[row, col+1]   = ObjectType::Wall_h;
    content[row+1, col]   = ObjectType::Space;
    
    startRow = endRow, startCol = endCol;
    while ((content[endRow, endCol] == ObjectType::Wall_v) || (content[endRow, endCol+1] == ObjectType::Brige)) {
        endRow--;
    }
    walls[i] = make_pair(make_pair(startRow, startCol), make_pair(endRow, endCol));
    
    //.|        --5
    //.|--
    //....
    content[row-1, col] = ObjectType::Wall_v;
    content[row, col-1] = ObjectType::Cell;
    content[row, col]   = ObjectType::Wall_v;
    content[row, col+1]   = ObjectType::Wall_h;
    content[row+1, col]   = ObjectType::Cell;
    
    startRow = endRow, startCol = endCol;
    while ((content[endRow, endCol+1] == ObjectType::Wall_h) || (content[endRow, endCol+1] == ObjectType::Brige)) {
        endCol++;
    }
    walls[i] = make_pair(make_pair(startRow, startCol), make_pair(endRow, ++endCol)); // same as left corner case
    
    //  |..     --6
    //--|..
    //.....
    content[row-1, col] = ObjectType::Wall_v;
    content[row, col-1] = ObjectType::Wall_h;
    content[row, col]   = ObjectType::Wall_v;
    content[row, col+1]   = ObjectType::Cell;
    content[row+1, col]   = ObjectType::Cell;
    
    startRow = endRow, startCol = endCol;
    while ((content[endRow, endCol-1] == ObjectType::Wall_h) || (content[endRow, endCol+1] == ObjectType::Brige)) {
        endCol--;
    }
    walls[i] = make_pair(make_pair(startRow, startCol), make_pair(endRow, --endCol));
    
    //.....     --7
    //..|--
    //..|
    content[row-1, col] = ObjectType::Cell;
    content[row, col-1] = ObjectType::Cell;
    content[row, col]   = ObjectType::Wall_v;
    content[row, col+1]   = ObjectType::Wall_h;
    content[row+1, col]   = ObjectType::Wall_v;
    
    startRow = endRow, startCol = endCol;
    while ((content[endRow, endCol+1] == ObjectType::Wall_h) || (content[endRow, endCol+1] == ObjectType::Brige)) {
        endCol++;
    }
    walls[i] = make_pair(make_pair(startRow, startCol), make_pair(endRow, ++endCol));
    
    
    //.....     --8
    //--|..
    //  |..
    content[row-1, col] = ObjectType::Cell;
    content[row, col-1] = ObjectType::Wall_h;
    content[row, col]   = ObjectType::Wall_v;
    content[row, col+1]   = ObjectType::Cell;
    content[row+1, col]   = ObjectType::Wall_v;
    
    startRow = endRow, startCol = endCol;
    while ((content[endRow, endCol-1] == ObjectType::Wall_h) || (content[endRow, endCol+1] == ObjectType::Brige)) {
        endCol--;
    }
    walls[i] = make_pair(make_pair(startRow, startCol), make_pair(endRow, --endCol));
    
}

void Floor::notify(std::shared_ptr<Subject> s){
    
    if(!s->isVisible) td->notify(s, true);
    this->coods = s->getCoordinates();
    if ((s->getType != SubjectType::Potion) && (s->getType != SubjectType::Gold)){
        this->gold = s->getGold();
        this->hp = s->getHP();
        this->atk = s->getAttack();
        this->def = s->getDefense();
    }
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
    
        int i;
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
        
        if (neighbors[i] != nullptr ){
            if (dir == "we" && neighbors[i] -> Subject::getType() ==
                Stariway){
                Game::generateNextFloor();
                return true;
            }
            else return false;
        }
        else{
            td->notify(s, true);
            Character::move(dir, s);
            td->notify(s, false);
            return true;
        }
        
        return false;

    
}













