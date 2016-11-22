#include "../Spell.h"
#include "catch.hpp"

TEST_CASE("test Spell class", "[Spell]") {
    Spell* f1 = new Spell();
    // Spell f2();
    
    REQUIRE (f1->getCurrentSpell() == fireball);
    
    f1->setSpell(heal);
    
    
    REQUIRE (f1->getCurrentSpell() == fireball);
    
    delete f1;
}
