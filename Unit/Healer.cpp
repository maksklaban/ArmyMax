#include "Healer.h"

Healer::Healer(std::string nickName, int damage, int hitPoints, int manaPoints, std::string title) : Spellcaster(nickName, damage, hitPoints, manaPoints, title) {}

Healer::~Healer() {}

void Healer::castFireball(Unit* enemy) {
    Spellcaster::castFireball(enemy);
    
    enemy->takeMagDamage(this->getMagDamage() / 2);
}

void Healer::castHeal(Unit* other) {
    Spellcaster::castHeal(other);
    
    other->addHitPoints(this->getMagDamage());
}
