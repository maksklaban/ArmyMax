#include "Priest.h"

Priest::Priest(std::string nickName, int damage, int hitPoints, int manaPoints, std::string title) : Spellcaster(nickName, damage, hitPoints, manaPoints, title) {}

Priest::~Priest() {}

void Priest::castSpell(Unit* other, CAST_ENUM spell) {
    Spellcaster::castSpell(other, spell);

    std::map<CAST_ENUM, Spell>::iterator it = this->spellBook->find(spell);

    if ( it->second.getIsBattle() ) {
        if ( other->getIsUndead() ) {
            other->takeMagDamage(it->second.getActionPoints());
            return;
        }

        other->takeMagDamage(it->second.getActionPoints() / 2);
    } else {
        other->addHitPoints((it->second.getActionPoints()));
    }
}


void Priest::attack(Unit* enemy) {
    if ( !(enemy->getIsUndead()) ) {
        enemy->takePhysicalDamage(this->getDamage());
    } else {
        enemy->takePhysicalDamage(this->getDamage() * 2);
    }

    enemy->counterAttack(this);
}

void Priest::counterAttack(Unit* enemy) {
    if ( !(enemy->getIsUndead()) ) {
        enemy->takePhysicalDamage(this->getDamage() / 2);
    } else {
        enemy->takePhysicalDamage(this->getDamage());
    }
}