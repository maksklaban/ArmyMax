#include "Unit.h"

Unit::Unit(int damage, int hitPoints, std::string nickName, std::string title) : nickName(nickName), state(new State(hitPoints, damage, title)) {}

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

const std::string& Unit::getTitle() const {
    return this->state->getTitle();
}

const State& Unit::getState() const {
    return *(this->state);
}

void Unit::takeDamage(int dmg) {
    this->state->takeDamage(dmg);
}

void Unit::addHitPoints(int hp) {
    this->state->addHitPoints(hp);
}

void Unit::attack(Unit* enemy) {
    enemy->takeDamage(this->getDamage());
    enemy->counterAttack(this); 
}

void Unit::counterAttack(Unit* enemy) {
    enemy->takeDamage(this->getDamage() / 2);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getNickName() << " " << unit.getState();
    
    return out;
}
