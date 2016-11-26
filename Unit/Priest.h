#ifndef PRIEST_H
#define PRIEST_H

#include "Spellcaster.h"

class Priest : public Spellcaster {
    public:
        Priest(std::string nickName, int damage=20, int hitPoints=150, int manaPoints=115, std::string title="Priest");
        virtual ~Priest();
        
        virtual void castSpell(Unit* other, CAST_ENUM spell);
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif // PRIEST_H

