#ifndef DEMON_H
#define DEMON_H

#include "Soldier.h"

// class Warlock;

class Demon : public Soldier {
    protected:
        Warlock* owner;

        void ensureHisOwner();
        
    public:
        Demon(std::string nickName, int damage=35, int hitPoints=190, std::string title="Demon", Warlock* owner);
        virtual ~Demon();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif // DEMON_H
