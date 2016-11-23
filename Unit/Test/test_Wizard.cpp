#include "../Wizard.h"
#include "catch.hpp"
#include <iostream>

TEST_CASE("test Wizard class", "[Wizard]") {
    Wizard* f1 = new Wizard("Nagibator");
    // Wizard* f2 = new Wizard("TvoyaMamka");
    Wizard* f2 = new Wizard("TvoyaMamka");
    
    REQUIRE(f1->getDamage() == 15 );
    REQUIRE(f1->getHitPoints() == 150);
    
    f1->castSpell(f2, Fireball);
    
    REQUIRE(f2->getHitPoints() == 110);
    
    f1->castSpell(f2, Heal);
    
    REQUIRE(f2->getHitPoints() == 132);
    
    f1->attack(f2);
    
    REQUIRE(f2->getHitPoints() == 117);
    REQUIRE(f1->getHitPoints() == 143);
    REQUIRE(f1->getIsVampire() == false);
    REQUIRE(f2->getIsUndead() == false);
    // f1->getUnitState();
    // f1->getSpellBook();
    
    REQUIRE(f1->getManaPoints() == 35);
    
    // REQUIRE(f2->getManaPoints() == 100);
    // REQUIRE()
    // f1->showSpellList();
    // std::cout << *f1 << std::endl;
    // std::cout << f2 << std::endl;
};
