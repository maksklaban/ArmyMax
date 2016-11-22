#include "Spellcaster.h"

Spellcaster::Spellcaster(std::string nickName, int damage, int hitPoints, int manaPoints, std::string title) : Unit(nickName, damage, hitPoints, title), manaPoints(manaPoints), manaPointsLimit(manaPoints) {
    this->spellBook = new std::map<CAST_ENUM, Spell>();
    this->spellBook->insert(std::pair<CAST_ENUM, Spell>(Fireball, Spell(Fireball, 40, 30, true)));
    this->spellBook->insert(std::pair<CAST_ENUM, Spell>(Heal, Spell(Heal, 45, 35, false)));
}

Spellcaster::~Spellcaster() {}

const int Spellcaster::getManaPoints() const {
    return this->manaPoints;
}

const int Spellcaster::getManaPointsLimit() const {
    return this->manaPointsLimit;
}

const std::map<CAST_ENUM, Spell>& Spellcaster::getSpellBook() const {
    return *(this->spellBook);
}

void Spellcaster::ensureIsAlive() {
    if ( Unit::getHitPoints() == 0 ) {
        throw NoHitPointsException();
    }
}

const void Spellcaster::showSpellBook() const {
    std::map<CAST_ENUM, Spell>::iterator it;
    
    std::cout << "Current spellbook: ";
    
    for ( it = this->spellBook->begin(); it != this->spellBook->end(); it++ ) {
        std::cout << std::endl << it->second;
    }
}

void Spellcaster::addManaPoints(int mp) {
    this->ensureIsAlive();
    
    int total = this->manaPoints + mp;
    
    if ( total > this->manaPointsLimit ) {
        this->manaPoints = this->manaPointsLimit;
        return;
    }
    
    this->manaPoints = total;
}

void Spellcaster::spendManaPoints(int mp) {
    this->ensureIsAlive();
    
    if ( mp > this->manaPoints ) {
        throw NoManaPointsException();
    }
    
    this->manaPoints -= mp;
}

void Spellcaster::attack(Unit* enemy) {
    enemy->takePhysDamage(this->getDamage());
    enemy->counterAttack(this); 
}

void Spellcaster::counterAttack(Unit* enemy) {
    enemy->takePhysDamage(this->getDamage() / 2);
}

void Spellcaster::castSpell(Unit* other, CAST_ENUM spell) {
    std::map<CAST_ENUM, Spell>::iterator it = this->spellBook->find(spell);

    if ( it == spellBook->end() ) {
        throw SpellIsNotAvaibleException();
    }

    this->spendManaPoints(it->second.Spell::getManaCost());

}

std::ostream& operator<<(std::ostream& out, const Spellcaster& spellcaster) {
    out << (Unit)spellcaster << ", ManaPoints " << spellcaster.getManaPoints() << "/" << spellcaster.getManaPointsLimit() << ";" << std::endl;
    spellcaster.showSpellBook();
    
    return out;
}
