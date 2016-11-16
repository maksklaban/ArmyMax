#ifndef SPELL_H
#define SPELL_H
#define FOREACH_SPELL(SPELL) \
              SPELL(fireball) \
              SPELL(heal) \
              SPELL(summonDemon) \

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

#include <set>
#include <iostream>
#include "../exception.h"

enum CAST_ENUM {
    FOREACH_SPELL(GENERATE_ENUM)
};

static const char *SPELL_STRING[] = {
    FOREACH_SPELL(GENERATE_STRING)
};

class Spell {
    protected:
        std::set<CAST_ENUM>* spellList;
        CAST_ENUM currentSpell;
        
    public:
        Spell();
        virtual ~Spell();
        
        const void showSpellList() const;
        const char* getCurrentSpell() const;
        
        void setSpell(CAST_ENUM spell); 
};

std::ostream& operator<<(std::ostream& out, const Spell& spell);

#endif //SPELL_H
