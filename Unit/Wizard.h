#ifndef WIZARD_H
#define WIZARD_H

#include "Spellcaster.h"

class Wizard : public Spellcaster {
    public:
        Wizard(std::string nickName, int damage=35, int hitPoints=150, int manaPoints=100, std::string title="Wizard");
        virtual ~Wizard();
        
        virtual void castFireball(Unit* enemy);
        virtual void castHeal(Unit* enemy);
};

#endif //WIZARD_H
