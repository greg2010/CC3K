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
#include <istringstream>
#include <string>
#include <algorithm>

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
        int coordRow = 0;
        int coordCol = 0;
        for (auto objType : contents) {
            if ((objType == ObjectType::Wall_v || obj == ObjectType::Wall_h) && !this->searchInChambers(coordRow, coordCol){
                this->createNewChamber(coordRow, coordCol);
            }
            ++coordCol;
            if (coordCol == 79) {
                coordCol = 0;
                ++coordRow;
            }
        }
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
                       
bool Floor::searchInChambers(int row, int col){
    for (auto ch : chambers) {
        if(find(ch->getCoords().begin(), ch->getCoords().end(), pair<int,int>{row, col}))  return true;
    }
    return false;
}
                       
void Floor::createNewChamber(int row, int col) {
    shared_ptr<Chamber> newChamber;
    int newRow = row, newCol = col;
    do {
        newChamber.addCoords(pair<int,int>{newRow, newCol});
        char dir;
        if (content[pair<int,int>{newRow, newCol + 1}] == ObjectType::Wall_h ||
            content[pair<int,int>{newRow, newCol + 1}] == ObjectType::Wall_v) {
            ++newCol;
        } else if (content[pair<int,int>{newRow + 1, newCol}] == ObjectType::Wall_h ||
                   content[pair<int,int>{newRow + 1, newCol}] == ObjectType::Wall_v) {
            ++newRow;
        } else if (content[pair<int,int>{newRow, newCol - 1}] == ObjectType::Wall_h ||
                   content[pair<int,int>{newRow, newCol - 1}] == ObjectType::Wall_v) {
            --newCol;
        }  else if (content[pair<int,int>{newRow - 1, newCol}] == ObjectType::Wall_h ||
                    content[pair<int,int>{newRow - 1, newCol}] == ObjectType::Wall_v) {
            --newRow;
        }
        
    } while (newRow != row && newCol != col);
    /*
    ObjectType type = content[make_pair(row, col)];
    newChamber.addCoords(row, col);
    int newRow = row, newCol = col;
    char dir = 'e';
    do {
        if(type == ObjectType::Wall_v) {
            type = ObjectType::Wall_h;
        }
        else if (type == ObjectType::Wall_h) {
            type = ObjectType::Wall_v;
        }
        if (content[make_pair(newRow, newCol + 1)] == type)   dir = 'e';
        else if (content[make_pair(newRow+1, newCol)] == type)   dir = 's';
        else if (content[make_pair(newRow, newCol-1)] == type)   dir = 'w';
        else if (content[make_pair(newRow-1, newCol)] == type)   dir = 'n';
        while (content[make_pair(newRow, newCol)] == type) {
            if (dir == 'e'){
                newChamber->addCoords(make_pair(newRow, newCol++));
            }
            else if (dir == 's') {
                newChamber->addCoords(make_pair(newRow++, newCol));
            }
            else if (dir == 'w') {
                newChamber->addCoords(make_pair(newRow, newCol--));
            }
            else if (dir == 'n') {
                newChamber->addCoords(make_pair(newRow--, newCol));
            }
        }
        if(dir == 's')  newRow--;
        if(dir == 'n')  newRow++;
        type = content[make_pair(newRow, newCol)];
    }while (newRow != row && newCol != col)
     */
    chambers.push_back[newChamber];
}

                       
vector<shared_ptr<Chamber> > Floor::getChamber() {
    return this->chambers;
}








