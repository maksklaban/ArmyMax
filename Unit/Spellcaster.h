#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include <map>
#include "Spell.h"
#include "Unit.h"

class Spellcaster : public Unit {
    protected:
        std::map<CAST_ENUM, Spell>* spellBook;
        int manaPoints;
        int manaPointsLimit;
        
        void ensureIsAlive();
    public:
        Spellcaster(std::string nickName, int damage, int hitPoints, int manaPoints, std::string title);
        virtual ~Spellcaster();
        
        const std::map<CAST_ENUM, Spell>& getSpellBook() const;
        const int getManaPoints() const;
        const int getManaPointsLimit() const;
        const void showSpellBook() const;
        
        void addManaPoints(int mp);
        void spendManaPoints(int mp);
        
        virtual void castSpell(Unit* other, CAST_ENUM spell);
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Spellcaster& spellcaster);

#endif //SPELLCASTER_H
