#include "Spell.h"

Spell::Spell(CAST_ENUM spellName, int actionPoints, int manaCost, bool isBattle) : spellName(spellName), actionPoints(actionPoints), manaCost(manaCost), isBattle(isBattle) {}

Spell::~Spell() {} 

const CAST_ENUM Spell::getSpellName() const {
    return this->spellName;
}

const int Spell::getManaCost() const {
    return this->manaCost;
}

const int Spell::getActionPoints() const {
    return this->actionPoints;
}

const bool Spell::getIsBattle() const {
    return this->isBattle;
}

std::ostream& operator<<(std::ostream& out, const Spell& spell) {
    out << SPELL_STRING[spell.getSpellName()] << ": Spellpower - " << spell.getActionPoints() << ", Manacost - " << spell.getManaCost() << ";";
    
    return out;
}
