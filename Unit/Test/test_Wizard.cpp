#include "../Wizard.h"
#include "../Soldier.h"
#include "../Rogue.h"
#include "../Berserk.h"
#include "catch.hpp"
#include <iostream>

TEST_CASE("test Wizard class", "[Wizard]") {
    Wizard* f1 = new Wizard("Nagibator");
    // Wizard* f2 = new Wizard("TvoyaMamka");
    Wizard* f2 = new Wizard("TvoyaMamka");
    Soldier* f3 = new Soldier("VASYA");
    Soldier* f4 = new Soldier("PETYA");
    Rogue* f5 = new Rogue("KATYA");
    Rogue* f6 = new Rogue("voRishKA");
    Berserk* f7 = new Berserk("BEZUMEC");
    Berserk* f8 = new Berserk("NEUDERZHIMIY");


    SECTION("Berserk test") {
        REQUIRE(f7->getDamage() == 25);
        REQUIRE(f8->getHitPoints() == 210);

        f7->attack(f8);

        REQUIRE(f8->getHitPoints() == 185);
        REQUIRE(f7->getHitPoints() == 198);

        f2->castSpell(f8, Fireball);
        f2->castSpell(f7, Heal);

        REQUIRE(f7->getHitPoints() == 198);
        REQUIRE(f8->getHitPoints() == 185);
        // REQUIRE(f3->getNickName() == "VASYA");
    }

    SECTION("Rogue test") {
        REQUIRE(f5->getDamage() == 40);
        REQUIRE(f6->getHitPoints() == 160);

        f5->attack(f6);

        REQUIRE(f6->getHitPoints() == 120);
        REQUIRE(f5->getHitPoints() == 160);
        // REQUIRE(f3->getNickName() == "VASYA");
    }

    SECTION("Soldiers test") {
        REQUIRE(f3->getDamage() == 30);
        REQUIRE(f4->getHitPoints() == 200);

        f3->attack(f4);

        REQUIRE(f4->getHitPoints() == 170);
        REQUIRE(f3->getHitPoints() == 185);
        REQUIRE(f3->getNickName() == "VASYA");
    }


    SECTION("Wizards test") {
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
        REQUIRE(f1->getIsWolf() == false);
        REQUIRE(f1->getManaPoints() == 35);
    }
};
