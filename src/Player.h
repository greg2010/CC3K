#ifndef A05_PLAYER_H
#define A05_PLAYER_H

#include <memory>
#include "Character.h"

class ConcreteGoldStashNormal;
class Potion;
class PotHP;
class ConcreteGoldStashGuarded;
class ConcreteStairway;

class Player : public Character {
public:
    Player(int HP, int atk, int def, std::pair<int,int> coords);
    void interact(std::shared_ptr<ConcreteGoldStashNormal> item);
    void interact(std::shared_ptr<ConcreteGoldStashGuarded> item);
    void interact(std::shared_ptr<Potion> item);
    void interact(std::shared_ptr<PotHP> hpPot);
    void interact(std::shared_ptr<ConcreteStairway> item);

    SubjectType getType();

     void assignCoords (std::pair<int, int> coords);

    virtual unsigned int getAttack();
    virtual unsigned int getDefence();

    void pushPotion(std::shared_ptr<Potion> pot); // Adds potion as decorator
protected:
    virtual void doInteract(std::shared_ptr<ConcreteGoldStashNormal> item);
    virtual void doInteract(std::shared_ptr<ConcreteGoldStashGuarded> item);

    virtual void doInteract(std::shared_ptr<PotHP> hpPot);

    unsigned int getPotAttack();
    unsigned int getPotDefence();

private:
    std::shared_ptr<Potion> potDec;
};


#endif //A05_PLAYER_H
