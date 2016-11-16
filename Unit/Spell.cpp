#include "Spell.h"

Spell::Spell() {
    this->spellList = new std::set<CAST_ENUM>();
    this->currentSpell = CAST_ENUM(fireball);
    this->spellList->insert(fireball);
    this->spellList->insert(heal);
} 

Spell::~Spell() {}

const char* Spell::getCurrentSpell() const {
    return SPELL_STRING[this->currentSpell];
}

const void Spell::showSpellList() const {
    std::set<CAST_ENUM>::iterator it;
    
    std::cout << "Current spellbook: ";
    
    for ( it = this->spellList->begin(); it != this->spellList->end(); it++ ) {
        std::cout << SPELL_STRING[*it] << " ";
    }
    
    std::cout << std::endl;
}

void Spell::setSpell(CAST_ENUM spell) {
    if ( this->spellList->count(spell) != 0 ) {
        this->currentSpell = spell;
    } else {
        throw SpellIsNotAvaibleException();
    }
}

std::ostream& operator<<(std::ostream& out, const Spell& spell) {
    spell.showSpellList();
    out << "Active spell: " << spell.getCurrentSpell();
    
    return out;
}
