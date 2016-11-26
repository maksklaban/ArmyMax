#ifndef HEALER_H
#define HEALER_H

#include "Spellcaster.h"

class Healer : public Spellcaster {
    public:
        Healer(std::string nickName, int damage=20, int hitPoints=160, int manaPoints=110, std::string title="Healer");
        virtual ~Healer();
        
        virtual void castSpell(Unit* other, CAST_ENUM spell);
};


#endif //HEALER_H
