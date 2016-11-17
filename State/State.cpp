#include "State.h"

State::State(int hitPoints, int damage, std::string title) : hitPoints(hitPoints), hitPointsLimit(hitPoints), damage(damage), title(title) {
    ensureIsAlive();
}

State::~State() {}

const int State::getHitPoints() const {
    return  this->hitPoints;
}

const int State::getHitPointsLimit() const {
    return  this->hitPointsLimit;
}

 const int State::getDamage() const {
    return  this->damage;
}

const std::string& State::getTitle() const {
    return this->title;
}

void State::ensureIsAlive() {
    if (hitPoints == 0) {
        throw NoHitPointsException();
    }
}

void State::addHitPoints(int hp) {
    this->ensureIsAlive();
    
    int total = this->hitPoints + hp;
    
    if ( total > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
        return;
    }
    this->hitPoints = total;
}

void State::takeDamage(int dmg) {
    this->ensureIsAlive();
    
    if ( dmg > this->hitPoints ) {
        this->hitPoints = 0;
        return;
    }
    this->hitPoints -= dmg;
}

std::ostream& operator<<(std::ostream& out, const  State& state) {
    out << " - " << state.getTitle() << ", ";
    out << "HP " << state.getHitPoints() << "/" << state.getHitPointsLimit() << ", ";
    out << "Damage "<<state.getDamage();
    
    return out;
}
