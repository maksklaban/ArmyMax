#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"

class Werewolf : public Unit {
    public:
        Werewolf(std::string nickName, int damage=25, int hitPoints=200, std::string title="Werewolf");
        virtual ~Werewolf();

        void transformInToWolf();
        void transformBack();
};

#endif // WEREWOLF_H
