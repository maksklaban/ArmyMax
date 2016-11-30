#ifndef DEMON_H
#define DEMON_H

#include "Soldier.h"

class Demon : public Soldier {
    protected:
        Unit* owner;

        void ensureHisOwner(Unit* enemy);

    public:
        Demon(Unit* owner, std::string nickName="Part of Legion", int damage=35, int hitPoints=190, std::string title="Demon");
        virtual ~Demon();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif // DEMON_H
