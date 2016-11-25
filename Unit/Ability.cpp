#include "Ability.h"

Ability::Ability(bool isVampire, bool isWerewolf) : isVampire(isVampire), isWerewolf(isWerewolf) {}

Ability::~Ability() {}

const bool Ability::getIsWerewolf() const {
    return this->isWerewolf;
}

const bool Ability::getIsVampire() const {
    return this->isVampire;
}

void Ability::turnInVampire(Ability* enemy) {
    if ( !(enemy->isVampire) && !(enemy->isWerewolf) && this->isVampire ) {
        enemy->isVampire = true;
    } else {
        throw CantTurnThisUnitException();
    }
}

void Ability::turnInWerewolf(Ability* enemy) {
    if ( !(enemy->isVampire) && !(enemy->isWerewolf) && this->isVampire ) {
        enemy->isWerewolf = true;
    } else {
        throw CantTurnThisUnitException();
    }
}

std::ostream& operator<<(std::ostream& out, const Ability& ability) {
    if ( ability.getIsVampire() ) {
        out << "(Unit has a vampire abilties)";
    } 

    if (ability.getIsWerewolf() ) {
        out << "(Unit has a werewolf abilties)";
    }

    return out;
}
