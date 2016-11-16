#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"

class Soldier : public Unit {
    public:
        Soldier(std::string nickName, int damage=30, int hitPoints=200, std::string title="Soldier");
        virtual ~Soldier();

        virtual void attack(Unit* enemy);
};


#endif // SOLDIER_H
