#include "Wizard.h"

Wizard::Wizard(std::string nickName, int damage, int hitPoints, int manaPoints, std::string title) : Spellcaster(nickName, damage, hitPoints, manaPoints, title) {}

Wizard::~Wizard();

void Wizard::castFireball(Unit* enemy) {
    Unit::castFireball(enemy);
    
    enemy->takeDamage(this->damage);
}

void Wizard::castHeal(Unit* other) {
    Unit::castHeal(enemy);
    
    other->addHitPoints(this->damage);
}
