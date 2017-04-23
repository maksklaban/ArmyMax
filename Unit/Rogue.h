#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"

class Rogue : public Unit {
    public:
        Rogue(std::string nickName, int damage=40, int hitPoints=160, std::string title="Rogue");
        virtual ~Rogue();

        virtual void attack(Unit* enemy);
};

#endif //ROGUE_H
