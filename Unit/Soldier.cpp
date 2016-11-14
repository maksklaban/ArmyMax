#include "Soldier.h"

Soldier::Soldier(std::string nickName, int damage, int hitPoints, std::string title) : Unit(damage, hitPoints, nickName, title) {}

Soldier::~Soldier() {}

void Soldier::attack(Unit* enemy) {
    Unit::attack(enemy);
}
