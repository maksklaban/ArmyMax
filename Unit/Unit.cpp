#include "Unit.h"

Unit::Unit(std::string nickName, int damage, int hitPoints, std::string title, bool isUndead, bool isVampire, bool isWerewolf) : nickName(nickName), isUndead(isUndead), state(new State(hitPoints, damage, title)), ability(new Ability(isVampire, isWerewolf)) {}

Unit::~Unit() {
    delete state;
}

const std::string& Unit::getNickName() const {
    return this->nickName;
}

const int Unit::getDamage() const {
    return this->state->getDamage();
}

const int Unit::getHitPoints() const {
    return this->state->getHitPoints();
}

const int Unit::getHitPointsLimit() const {
    return this->state->getHitPointsLimit();
}

const bool Unit::getIsUndead() const {
    return this->isUndead;
}

const std::string& Unit::getTitle() const {
    return this->state->getTitle();
}

const State& Unit::getState() const {
    return *(this->state);
}

const Ability& Unit::getAbility() const {
    return *(this->ability);
}

void Unit::takeMagDamage(int dmg) {
    this->state->takeMagDamage(dmg);
}

void Unit::takePhysicalDamage(int dmg) {
    this->state->takeDamage(dmg);
}

void Unit::addHitPoints(int hp) {
    this->state->addHitPoints(hp);
}

void Unit::attack(Unit* enemy) {
    enemy->takePhysicalDamage(this->getDamage());
    enemy->counterAttack(this); 
}

void Unit::counterAttack(Unit* enemy) {
    enemy->takePhysicalDamage(this->getDamage() / 2);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getNickName() << (Ability)unit << unit.getState();
    
    return out;
}
