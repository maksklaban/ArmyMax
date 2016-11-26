#include "Necromanser.h"

Necromanser::Necromanser(std::string nickName, int damage, int hitPoints, int manaPoints, std::string title) : Spellcaster(nickName, damage, hitPoints, manaPoints, title, true) {}

Necromanser::~Necromanser() {}

void Necromanser::castSpell(Unit* other, CAST_ENUM spell) {
    Spellcaster::castSpell(other, spell);

    std::map<CAST_ENUM, Spell>::iterator it = this->spellBook->find(spell);

    if ( it->second.getIsBattle() ) {
        other->takeMagDamage(it->second.getActionPoints());
        this->addSubject(other);
    } else {
        other->addHitPoints((it->second.getActionPoints()) / 2);
    }
}

void Necromanser::attack(Unit* enemy) {
    Spellcaster::attack(enemy);

    this->addSubject(enemy);
}

void Necromanser::update(Unit* enemy) {
    this->addHitPoints(enemy->getHitPointsLimit() / 5);

    Observer::update(enemy);
}