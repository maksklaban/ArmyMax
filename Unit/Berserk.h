#ifndef BERSERK_H
#define BERSERK_H

#include "Unit.h"

class Berserk : public Unit {
    public:
        Berserk(std::string nickName, int damage=25, int hitPoints=210, std::string title="Berserk");
        virtual ~Berserk();

        virtual void addHitPoints(int hp);
        virtual void takeMagDamage(int dmg);
};

#endif // BERSERK_H
