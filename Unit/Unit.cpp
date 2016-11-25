#include "Unit.h"

Unit::Unit(std::string nickName, int damage, int hitPoints, std::string title, bool isUndead, bool isVampire, bool isWerewolf) : nickName(nickName), isUndead(isUndead), state(new State(hitPoints, damage, title, false)), Ability(isVampire, isWerewolf), Subject() {
    this->normalState = new State(hitPoints, damage, title, false);
    this->wolfState = new State((hitPoints * 1.5), (damage * 2), "WolfForm", true);
}

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

const bool Unit::getIsWolf() const {
    return this->state->getIsWolf();
}

const std::string& Unit::getTitle() const {
    return this->state->getTitle();
}

const State& Unit::getState() const {
    return *(this->state);
}

void Unit::takeMagDamage(int dmg) {
    if ( !(this->getIsWolf())) {
        this->state->takeDamage(dmg);
    } else {
        this->state->takeDamage(dmg*2);
    }
}

void Unit::takePhysicalDamage(int dmg) {
    this->state->takeDamage(dmg);
}

void Unit::addHitPoints(int hp) {
    this->state->addHitPoints(hp);
}

void Unit::turnInVampire(Unit* enemy) {
    Ability::turnInVampire(enemy);

    enemy->isUndead = true;
}

void Unit::transformInToWolf() {
    if ( this->isWerewolf ) {
        this->state = this->wolfState;
    } else {
        throw UnitCantTransformException();
    }
}

void Unit::transformBack() {
    if ( this->getIsWolf() ) {
        this->state = this->normalState;
    } else {
        throw UnitCantTransformException();
    }
}

void Unit::vampireAttack(Unit* enemy) {
    if ( this->getIsVampire() ) {
        this->attack(enemy);
        this->addHitPoints(this->getDamage() / 3);
    } else {
        throw AbilityIsNotAvaibleException();
    }
}

void Unit::attack(Unit* enemy) {
    enemy->takePhysicalDamage(this->getDamage());
    enemy->counterAttack(this); 
}

void Unit::counterAttack(Unit* enemy) {
    enemy->takePhysicalDamage(this->getDamage() / 2);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getNickName() << " " << (Ability)unit << unit.getState();
    
    return out;
}
