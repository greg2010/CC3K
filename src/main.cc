//
//  main.cc
//  cc3k2
//
//  Created by YoY on 2016-07-24.
//  Copyright © 2016 YoY. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "Game.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    //check command line arguments
    
    int seed = 1;
    fstream file;
    if (argc >= 2) {
        file.open(argv[1], fstream::in);
        if (argc == 3) {
            seed = stoi(argv[2]);
        }
    }
    else {
        file.open("defaultLayout.txt", fstream::in);
    }
    
    // start game
    shared_ptr<Game> game = make_shared<Game>(file, seed);
    string input;
    game->display();
    while (getline(cin, input)){
        istringstream iss(input);
        char c;
        iss >> c;
        if (c == 'n' || c == 's' || c == 'w' || c == 'e') {
            if (input == "no" || input == "nw" || input == "ne" || input == "so" || input == "sw" || input == "se" || input == "ea" || input == "we") {
                game->movePlayer(input);
            }
            else continue;
        }
        else if (c == 'u') {
            string dir = "";
            iss >> c;
            dir += c;
            iss >> c;
            dir += c;
            
            if (dir == "no" || dir == "nw" || dir == "ne" || dir == "so" || dir == "sw" || dir == "se" || dir == "ea" || dir == "we") {
                game->usePotion(dir);
            }
        }
        else if (c == 'a') {
            string dir = "";
            iss >> c;
            dir += c;
            iss >> c;
            dir += c;
            
            if (dir == "no" || dir == "nw" || dir == "ne" || dir == "so" || dir == "sw" || dir == "se" || dir == "ea" || dir == "we") {
                game->attack(dir);
            }

        }
        else if (c == 'r') {
            game = make_shared<Game>(file, seed);
            continue;
        }
        else if (c == 'q') {
            exit(0);
        }
        game->display();
    }
    
    
}
