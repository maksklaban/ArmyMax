#include "Warlock.h"

Warlock::Warlock(std::string nickName, int damage, int hitPoints, int manaPoints, std::string title) : Wizard(nickName, damage, hitPoints, manaPoints, title), list(new std::set<Demon*>()) {}

Warlock::~Warlock() {
    std::set<Demon*>::iterator it;

    for ( it = list->begin(); it != list->end(); it++ ) {
        Demon* obs = *it;

        obs->~Demon();
    }
}

Demon* Warlock::summonDemon() {
    if ( this->getHitPoints() > 0 ) {
        Demon* temp = new Demon(this);

        this->list->insert(temp);

        return temp;
    } else {
        throw NoHitPointsException();
    }
}