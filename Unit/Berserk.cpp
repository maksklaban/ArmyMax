#include "Berserk.h"

Berserk::Berserk(std::string nickName, int damage, int hitPoints, std::string title) : Unit(nickName,damage, hitPoints, title) {}

Berserk::~Berserk() {}

void Berserk::addHitPoints(int hp) {
    this->state->addHitPoints(0);
}

void Berserk::takeMagDamage(int dmg) {
    if ( !(this->getIsWolf())) {
        this->state->takeDamage(0);
    } else {
        this->state->takeDamage(dmg*2);
    }
}
