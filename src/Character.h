#ifndef A05_CHARACTER_H
#define A05_CHARACTER_H


#include "Subject.h"

class Character : Subject {
public:
    Character(int HP, int atk, int def, std::pair<int,int> coords); // Constructs character
    unsigned int getHP();
    virtual unsigned int getAttack();
    virtual unsigned int getDefence();
    bool move(std::string dir); // Moves chararcter in direction dir. Checks if movement is possible (?)
    void attackedBy(std::shared_ptr<Character> attacker); // Handles attacks
    unsigned int getGold();
    bool hasMoved(); // getter for hasMovedThisTurn
    void resetMove(); // resets hasMovedThisTurn
    void pushPotion(std::shared_ptr<Potion> pot); // Adds potion as decorator
    virtual ~Character() = 0;
private:
    bool hasMovedThisTurn;
    int HP;
    int atk;
    int def;
    int gold;
    std::shared_ptr<Potion> potPtr;
};



#endif //A05_CHARACTER_H
