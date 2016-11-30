#include "Warlock.h"

Warlock::Warlock(std::string nickName, int damage, int hitPoints, int manaPoints, std::string title) : Wizard(nickName, damage, hitPoints, manaPoints, title) {}

Warlock::~Warlock() {
    this->notifyMinions();
}

Demon* Warlock::summonDemon() {
    if ( this->getHitPoints() > 0 ) {
        Demon* temp = new Demon(this);

        this->addSubject(temp);

        return temp;
    } else {
        throw NoHitPointsException();
    }
}

void Warlock::notifyMinions() {
    std::set<Subject*>::iterator it;

    for ( it = set->begin(); it != set->end(); it++ ) {
        Subject* subj = *it;

        subj->~Subject();
    }
}