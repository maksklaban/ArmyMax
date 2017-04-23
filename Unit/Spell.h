#ifndef SPELL_H
#define SPELL_H
#define FOREACH_SPELL(SPELL) \
              SPELL(Fireball) \
              SPELL(Heal) \

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

#include <iostream>
#include "../exception.h"

enum CAST_ENUM {
    FOREACH_SPELL(GENERATE_ENUM)
};

static const std::string SPELL_STRING[] = {
    FOREACH_SPELL(GENERATE_STRING)
};

class Spell {
    protected:
        CAST_ENUM spellName;
        int actionPoints;
        int manaCost;
        bool isBattle;
        
    public:
        Spell(CAST_ENUM spellName, int actionPoints, int manaCost, bool isBattle);
        virtual ~Spell();
        
        const CAST_ENUM getSpellName() const;
        const int getManaCost() const;
        const int getActionPoints() const;
        const bool getIsBattle() const;
};

std::ostream& operator<<(std::ostream& out, const Spell& spell);

#endif //SPELL_H
