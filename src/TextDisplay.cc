//
//  TextDisplay.cpp
//  cc3k
//
//  Created by YoY on 2016-07-18.
//  Copyright © 2016 YoY. All rights reserved.
//

#include "TextDisplay.h"

TextDisplay::TextDisplay(int width, int height): w(width), h(height) {
    charMap[Player] = '@';
    charMap[Goblin] = 'N';
    charMap[Vampire] = 'V';
    charMap[Werewolf] = 'W';
    charMap[Merchant] = 'M';
    charMap[Dragon] = 'D';
    charMap[Phoenix] = 'X';
    charMap[Troll] = 'T';
    charMap[Potion] = 'P';
    charMap[Gold] = 'G';
    charMap[Stairway] = '\\';
}


