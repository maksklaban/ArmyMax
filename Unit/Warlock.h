#ifndef WARLOCK_H
#define WARLOCK_H

#include "Wizard.h"
#include "Demon.h"

class Demon;

class Warlock : public Wizard {
    public:
        Warlock(std::string nickName, int damage=15, int hitPoints=140, int manaPoints=100, std::string title="Warlock");
        virtual ~Warlock();
        
        virtual Demon* summonDemon();
        void notifyMinions();
};

#endif //WARLOCK_H
