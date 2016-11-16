#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include "Spell.h"
#include "Unit.h"
#include <iostream>

class Spellcaster : public Unit, public Spell {
    protected:
        Unit* unit;
        Spell* spellBook;
        int manaPoints;
        int manaPointsLimit;
        
        void ensureIsAlive();
    public:
        Spellcaster(std::string nickName, int damage, int hitPoints, int manaPoints, std::string title);
        virtual ~Spellcaster();
        
        const int getManaPoints() const;
        const int getManaPointsLimit() const;
        const Unit& getUnitState() const;
        const Spell& getSpellBook() const;
        
        void addManaPoints(int mp);
        void spendManaPoints(int mp);
        
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
        virtual void castFireball(Unit* enemy) = 0;
        virtual void castHeal(Unit* other) = 0;
};

std::ostream& operator<<(std::ostream& out, const Spellcaster& spellcaster);

#endif //SPELLCASTER_H