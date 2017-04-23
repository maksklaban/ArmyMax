#include "Rogue.h"

Rogue::Rogue(std::string nickName, int damage, int hitPoints, std::string title) : Unit(nickName,damage, hitPoints, title) {}

Rogue::~Rogue() {}

void Rogue::attack(Unit* enemy) {
    enemy->takePhysicalDamage(this->getDamage());
}

