//
//  TextDisplay.cc
//  cc3k
//
//  Created by YoY on 2016-07-18.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "TextDisplay.h"
#include "Subject.h"
#include "Player.h"
#include "Observer.h"

#include <iomanip>
#include <memory>

using namespace std;
TextDisplay::TextDisplay(std::shared_ptr<Player> pc, int currFloor, string race, int width, int height): pc(pc), race(race), currFloor(currFloor), w(width), h(height), messageCounter(0), message("") {
    charMap[SubjectType::Player] = '@';
    charMap[SubjectType::Goblin] = 'N';
    charMap[SubjectType::Vampire] = 'V';
    charMap[SubjectType::Werewolf] = 'W';
    charMap[SubjectType::Merchant] = 'M';
    charMap[SubjectType::Dragon] = 'D';
    charMap[SubjectType::Phoenix] = 'X';
    charMap[SubjectType::Troll] = 'T';
    charMap[SubjectType::RH] = 'P';
    charMap[SubjectType::PH] = 'P';
    charMap[SubjectType::BA] = 'P';
    charMap[SubjectType::WA] = 'P';
    charMap[SubjectType::BD] = 'P';
    charMap[SubjectType::WD] = 'P';
    charMap[SubjectType::Gold] = 'G';
    charMap[SubjectType::Stairway] = '\\';
    charMap[SubjectType::Cell] = '.';
    charMap[SubjectType::Door] = '+';
    charMap[SubjectType::Bridge] = '#';
    string message = " Player character has spawned.";
}


void TextDisplay::notify(std::shared_ptr<Subject> sub, bool off) {
    if (off){
        grid[sub->getCoordinates().first][sub->getCoordinates().second] = '.';
    }
    else {
        grid[sub->getCoordinates().first][sub->getCoordinates().second] = charMap[sub->getType()];
    }
}
            
void TextDisplay::notify(std::shared_ptr<Item> item, bool off) {
    if (off){
        grid[item->getCoordinates().first][item->getCoordinates().second] = '.';
    }
    else {
        grid[item->getCoordinates().first][item->getCoordinates().second] = charMap[item->getType()];
    }
}

void operator<<(std::ostream &out, std::shared_ptr<TextDisplay> td) {
    for(int i = 0; i < td->grid.size(); i++){
        for(int j = 0; j < td->grid[i].size(); j++){
            out<<td->grid[i][j];
        }
        out << endl;
    }
    
    out << "Race: " << td->race
    << " Gold: "<< td->pc->getGold()
    << right << setw(td->grid[0].size()-27) << "Floor "<< td->currFloor << endl
    << "HP: "<< td->pc->getHP() << endl
    << "Atk: "<< td->pc->getAttack() << endl
    << "Def: "<< td->pc->getDefence() << endl
    << "Action: " << td->message << endl;
    td->message = "";
    td->messageCounter = 0;
}
void TextDisplay::drawLayout(istream &in) {
    vector<char> emp;
    for (int row = 0; row < h; row++) {
        grid.push_back(emp);
        for (int col = 0; col < w; col++) {
            char c;
            in >> std::noskipws >> c;
            if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5') {
               c = 'P';
            }
            if (c == '6' || c == '7' || c == '8' || c == '8') {
                c = 'G';
            }
            grid[row].push_back(c);
        }
    }
}

void TextDisplay::potionMessage(std::shared_ptr<Subject> sub) {
    string potName = "";
    if (sub->getType() == SubjectType :: RH) potName = "RH";
    else if (sub->getType() == SubjectType :: PH) potName = "PH";
    else if (sub->getType() == SubjectType :: BA) potName = "BA";
    else if (sub->getType() == SubjectType :: WA) potName = "WA";
    else if (sub->getType() == SubjectType :: BD) potName = "BD";
    else if (sub->getType() == SubjectType :: WD) potName = "WD";
    if (messageCounter) message += " ";
    message += "PC uses " + potName;
    ++messageCounter;
}

void TextDisplay::attackMessage(shared_ptr<Subject> attacker, shared_ptr<Subject> beingAttacked, int damage) {
    if (messageCounter) message += " ";
    if (attacker->getType() == SubjectType::Player) {
        message += "PC deals " + to_string(damage) + " damage to " + string{charMap[beingAttacked->getType()]} + " (" + to_string(dynamic_pointer_cast<Character>(beingAttacked)->getHP()) + " HP).";
    }
    else  {
        message += string{charMap[beingAttacked->getType()]} + " deals " + to_string(damage) + " damage to PC.";
    }
    ++messageCounter;
}

TextDisplay::~TextDisplay() { }


