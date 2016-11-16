#ifndef SPELL_H
#define SPELL_H
#define FOREACH_SPELL(SPELL) \
              SPELL(fireball) \
              SPELL(heal) \
              SPELL(summonDemon) \

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

#include <map>
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
        std::map<CAST_ENUM, int>* spellList;
        
        void addSpell(CAST_ENUM spell, int manaCost); 
    public:
        Spell();
        virtual ~Spell();
        
        const std::map<CAST_ENUM, int>& getSpellList() const; 
        const int getManaCost(CAST_ENUM spell, std::map<CAST_ENUM, int>* spellList );
        const void showSpellList() const;
};

std::ostream& operator<<(std::ostream& out, const Spell& spell);

#endif //SPELL_H
