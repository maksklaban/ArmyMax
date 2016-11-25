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
    if ( !(enemy->isVampire) && !(enemy->isWerewolf )) {
        enemy->isVampire = true;
    } else {
        throw CantTurnThisUnitException();
    }
}

void Ability::turnInWerewolf(Ability* enemy) {
    if ( !(enemy->isVampire) && !(enemy->isWerewolf )) {
        enemy->isWerewolf = true;
    } else {
        throw CantTurnThisUnitException();
    }
}

std::ostream& operator<<(std::ostream& out, const Ability& ability) {
    if ( ability.getIsVampire() ) {
        out << "Unit is vampire" << std::endl;
    } 

    if (ability.getIsWerewolf() ) {
        out << "Unit is werewolf" << std::endl;
    }

    return out;
}
