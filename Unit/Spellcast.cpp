#include "Spellcaster.h"

Spellcaster::Spellcaster(std::string nickName, int damage, int hitPoints, int manaPoints, std::string title) : Unit(nickName, damage, hitPoints, title), Spell(), manaPoints(manaPoints), manaPointsLimit(manaPoints) {}

Spellcaster::~Spellcaster() {}

const int Spellcaster::getManaPoints() const {
    return this->manaPoints;
}

const int Spellcaster::getManaPointsLimit() const {
    return this->manaPointsLimit;
}

const Unit& Spellcaster::getUnitState() const {
    return *(this->Unit);
}

const Spell& Spellcaster::getSpellList() const {
    return *(this->Spell);
}

void Spellcaster::ensureIsAlive() {
    if ( Unit::getHitPoints() == 0 ) {
        throw NoHitPointsException();
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

void Spellcaster::castFireball(Unit* enemy, std::map<CAST_ENUM, int>* spellList) {
    enemy->ensureIsAlive();
    
    this->spendManaPoints(this->getManaCost(fireball, spellList));
}

void Spellcaster::castHeal(Unit* other, std::map<CAST_ENUM, int>* spellList) {
    other->ensureIsAlive();
    
    this->spendManaPoints(this->getManaCost(heal, spellList));
}

std::ostream& operator<<(std::ostream& out, const Spellcaster& spellcaster) {
    out << spellcaster.getUnitState() << endl;
    out << spellcaster.getSpellList();
    
    return out;
}
