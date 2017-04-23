#ifndef ABILITY_H
#define ABILITY_H

#include "../exception.h"
#include <iostream>

class Ability {
    protected:
        bool isWerewolf;
        bool isVampire;

    public:
        Ability(bool isVampire=false, bool isWerewolf=false);
        virtual ~Ability();

        const bool getIsWerewolf() const;
        const bool getIsVampire() const;

        virtual void turnInWerewolf(Ability* enemy);
        virtual void turnInVampire(Ability* enemy);
};

std::ostream& operator<<(std::ostream& out, const Ability& ability);

#endif //ABILITY_H