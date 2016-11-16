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
    return *(this->unit);
}

const Spell& Spellcaster::getSpellBook() const {
    return *(this->spellBook);
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

void Spellcaster::attack(Unit* enemy) {
    enemy->takeDamage(this->getDamage() / 2);
    enemy->counterAttack(this); 
}

void Spellcaster::counterAttack(Unit* enemy) {
    enemy->takeDamage(this->getDamage() / 2);
}

void Spellcaster::castFireball(Unit* enemy) {
    this->spendManaPoints((this->getManaCost(fireball, this->spellList)));
}

void Spellcaster::castHeal(Unit* other) {
    this->spendManaPoints(this->getManaCost(heal, this->spellList));
}

std::ostream& operator<<(std::ostream& out, const Spellcaster& spellcaster) {
    out << spellcaster.getUnitState() << std::endl;
    out << spellcaster.getSpellBook();
    
    return out;
}
