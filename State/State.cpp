#include "State.h"

State::State(int hitPoints, int damage, std::string nickName) : hitPoints(hitPoints), hitPointsLimit(hitPoints), damage(damage), nickName(nickName) {}

State::~State() {}

const int State::getHitPoints() const {
    return  this->hitPoints;
}

const int State::getHitPoints() const {
    return  this->hitPoints;
}

const int State::getHitPointsLimit() const {
    return  this->hitPointsLimit;
}

 const int State::getDamage() const {
    return  this->damage;
}

const std::string State::getNickName() const {
    return this->nickName;
}

void State::ensureIsAlive() {
    if (hitPoints == 0) {
        throw NoHitPointsExcaption();
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

std::iostream& operator<<(std::iostream& out, const  State& state) {
    out << "[" << state.getNickName() << ", ";
    out << "HP " << state.getHitPoints() << "/" << state.getHitPointsLimit() << ", ";
    out << "Damage "<<state.getDamage() << "]";
    
    return out;
}
