#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"

class Vampire : public Unit {
    public:
        Vampire(std::string nickName, int damage=30, int hitPoints=180, std::string title="Vampire");
        virtual ~Vampire();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif // VAMPIRE_H
