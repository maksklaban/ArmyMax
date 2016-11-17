#ifndef HEALER_H
#define HEALER_H

#include "Spellcaster.h"

class Healer : public Spellcaster {
    public:
        Healer(std::string nickName, int damage=35, int hitPoints=140, int manaPoints=110, std::string title="Healer");
        virtual ~Healer();
        
        virtual void castFireball(Unit* enemy);
        virtual void castHeal(Unit* enemy);
};


#endif //HEALER_H
