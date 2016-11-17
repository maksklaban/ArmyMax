#include "Wizard.h"

Wizard::Wizard(std::string nickName, int damage, int hitPoints, int manaPoints, std::string title) : Spellcaster(nickName, damage, hitPoints, manaPoints, title) {}

Wizard::~Wizard() {};

void Wizard::castFireball(Unit* enemy) {
    Spellcaster::castFireball(enemy);
    
    enemy->takeMagDamage(this->getMagDamage());
}

void Wizard::castHeal(Unit* other) {
    Spellcaster::castHeal(other);
    
    other->addHitPoints(this->getMagDamage() / 2);
}
