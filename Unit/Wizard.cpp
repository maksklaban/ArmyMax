#include "Wizard.h"

Wizard::Wizard(std::string nickName, int damage, int hitPoints, int manaPoints, std::string title) : Spellcaster(nickName, damage, hitPoints, manaPoints, title) {}

Wizard::~Wizard() {};

void Wizard::castSpell(Unit* other, CAST_ENUM spell) {
    Spellcaster::castSpell(other, spell);

    std::map<CAST_ENUM, Spell>::iterator it = this->spellBook->find(spell);

    if ( it->second.getIsBattle() ) {
        other->takeMagDamage(it->second.getActionPoints());
    } else {
        other->addHitPoints((it->second.getActionPoints()) / 2);
    }
}
