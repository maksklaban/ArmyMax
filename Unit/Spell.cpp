#include "Spell.h"

Spell::Spell() {
    this->spellList = new std::map<CAST_ENUM, int>();
    this->addSpell(fireball, 30);
    this->addSpell(heal, 20);
} 

Spell::~Spell() {}

const std::map<CAST_ENUM, int>& Spell::getSpellList() const {
    return *(this->spellList);
}

const int Spell::getManaCost(CAST_ENUM spell, std::map<CAST_ENUM, int>* spellList ) {
    std::map<CAST_ENUM, int>::iterator it = spellList->find(spell);
    
    if ( it == spellList->end() ) {
        throw SpellIsNotAvaibleException();
    }
    return it->second;
}

const void Spell::showSpellList() const {
    std::map<CAST_ENUM, int>::iterator it;
    
    std::cout << "Current spellbook: ";
    
    for ( it = this->spellList->begin(); it != this->spellList->end(); it++ ) {
        std::cout << std::endl << SPELL_STRING[it->first] << " - manacost(" << it->second << ");";
    }
}

void Spell::addSpell(CAST_ENUM spell, int manaCost) {
    this->spellList->insert(std::pair<CAST_ENUM, int>(spell, manaCost));
}

std::ostream& operator<<(std::ostream& out, const Spell& spell) {
    spell.showSpellList();
    
    return out;
}
