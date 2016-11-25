#include "Vampire.h"

Vampire::Vampire(std::string nickName, int damage, int hitPoints, std::string title) : Unit(nickName,damage, hitPoints, title, true, true, false) {}

Vampire::~Vampire() {}

void Vampire::attack(Unit* enemy) {
    enemy->takePhysicalDamage(this->getDamage());
    
    this->addHitPoints(this->getDamage() / 3);

    enemy->counterAttack(this); 
    
}

void Vampire::counterAttack(Unit* enemy) {
    Unit::counterAttack(enemy);

    this->addHitPoints(this->getDamage() / 6);
}