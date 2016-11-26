#include "Demon.h"

Demon::Demon(Unit* owner, std::string nickName, int damage, int hitPoints, std::string title) : Soldier(nickName, damage, hitPoints, title), owner(owner) {}

Demon::~Demon() {}

void Demon::ensureHisOwner(Unit* enemy) {
    if ( enemy == this->owner ) {
        throw UnitCantAttackHisOwnerException();
    }
}

void Demon::attack(Unit* enemy) {
    ensureHisOwner(enemy);
    
    Unit::attack(enemy);
}

void Demon::counterAttack(Unit* enemy) {
    ensureHisOwner(enemy);

    Unit::counterAttack(enemy);
}