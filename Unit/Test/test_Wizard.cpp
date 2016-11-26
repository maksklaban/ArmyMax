#include "../Wizard.h"
#include "../Soldier.h"
#include "../Rogue.h"
#include "../Berserk.h"
#include "../Vampire.h"
#include "../Werewolf.h"
#include "../Healer.h"
#include "catch.hpp"
#include <iostream>

TEST_CASE("test Wizard class", "[Wizard]") {
    Wizard* f1 = new Wizard("Nagibator");
    Wizard* test2 = new Wizard("test");
    // Wizard* f2 = new Wizard("TvoyaMamka");
    Wizard* f2 = new Wizard("TvoyaMamka");
    Soldier* f3 = new Soldier("VASYA");
    Soldier* f4 = new Soldier("PETYA");
    Soldier* test = new Soldier("m9so");
    Soldier* test1 = new Soldier("m9sko");
    Rogue* f5 = new Rogue("KATYA");
    Rogue* f6 = new Rogue("voRishKA");
    Berserk* f7 = new Berserk("BEZUMEC");
    Berserk* f8 = new Berserk("NEUDERZHIMIY");
    Vampire* f9 = new Vampire("VLAD");
    Vampire* f10 = new Vampire("ConstantinVladimirovich");
    Werewolf* f11 = new Werewolf("SobakaUlubaka");
    Werewolf* f12 = new Werewolf("Barbos");
    Healer* f13 = new Healer("Dohtor");
    Healer* f14 = new Healer("VRACH");


    SECTION("Healer test") {
        REQUIRE(f13->getDamage() == 20 );
        REQUIRE(f13->getHitPoints() == 160);
        
        f13->castSpell(f14, Fireball);
        f13->castSpell(f14, Fireball);
        
        REQUIRE(f14->getHitPoints() == 120);
        
        f13->castSpell(f14, Heal);
        
        REQUIRE(f14->getHitPoints() == 160);
        
        f13->attack(f14);
        
        REQUIRE(f14->getHitPoints() == 140);
        REQUIRE(f13->getHitPoints() == 150);
        REQUIRE(f13->getIsVampire() == false);
        REQUIRE(f14->getIsUndead() == false);
        REQUIRE(f13->getIsWolf() == false);
        REQUIRE(f13->getManaPoints() == 15);

        f12->turnInWerewolf(f13);

        f13->transformInToWolf();

        f14->castSpell(f13, Fireball);

        REQUIRE(f13->getHitPoints() == 200);
    }

    SECTION("Vampire test") {
        REQUIRE(f9->getDamage() == 30);
        REQUIRE(f10->getHitPoints() == 180);

        f9->attack(f10);

        REQUIRE(f10->getHitPoints() == 155);
        REQUIRE(f9->getHitPoints() == 165);


        f9->turnInVampire(test);
        test->turnInVampire(test1);

        REQUIRE(test->getIsVampire() == true);
        REQUIRE(test->getIsUndead() == true);
        REQUIRE(test1->getIsUndead() == true);

        test->vampireAttack(test1);
        test1->vampireAttack(test);

        REQUIRE(test1->getHitPoints() == 165);
    }

    SECTION("Werewolf test") {
        REQUIRE(f11->getDamage() == 25);
        REQUIRE(f12->getHitPoints() == 200);

        f11->attack(f12);

        REQUIRE(f12->getHitPoints() == 175);
        REQUIRE(f11->getHitPoints() == 188);
        REQUIRE(f11->getIsWolf() == false);
        
        f11->transformInToWolf();

        test2->castSpell(f11, Fireball);
        
        REQUIRE(f11->getDamage() == 50);
        REQUIRE(f11->getIsWolf() == true);
        REQUIRE(f11->getHitPoints() == 220);
        REQUIRE(f11->getHitPointsLimit() == 300);

        f11->transformBack();
        
        REQUIRE(f11->getIsWolf() == false);
        REQUIRE(f11->getDamage() == 25);
        REQUIRE(f11->getHitPointsLimit() == 200);
        REQUIRE(f11->getHitPoints() == 200);
        
        test2->castSpell(f11, Fireball);

        REQUIRE(f11->getHitPoints() == 160);

        f11->turnInWerewolf(test2);

        REQUIRE(test2->getIsWerewolf() == true);

        test2->transformInToWolf();

        REQUIRE(test2->getIsWolf() == true);
    }


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
