#include "../Wizard.h"
#include "../Soldier.h"
#include "../Rogue.h"
#include "../Berserk.h"
#include "../Vampire.h"
#include "../Werewolf.h"
#include "../Healer.h"
#include "../Priest.h"
#include "../Demon.h"
#include "../Warlock.h"
#include "../Necromanser.h"
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
    Soldier* test5 = new Soldier("m9sko1");
    Rogue* f5 = new Rogue("KATYA");
    Rogue* f6 = new Rogue("voRishKA");
    Berserk* f7 = new Berserk("BEZUMEC");
    Berserk* f8 = new Berserk("NEUDERZHIMIY");
    Vampire* f9 = new Vampire("VLAD");
    Vampire* f10 = new Vampire("ConstantinVladimirovich");
    Vampire* test3 = new Vampire("onstantinVladimirovich");
    Werewolf* f11 = new Werewolf("SobakaUlubaka");
    Werewolf* f12 = new Werewolf("Barbos");
    Healer* f13 = new Healer("Dohtor");
    Healer* f14 = new Healer("VRACH");
    Priest* f15 = new Priest("Ioann");
    Priest* f16 = new Priest("KirillSv9toy");
    Warlock *f17 = new Warlock("GuldAn");
    Warlock *f18 = new Warlock("NerZul");
    Demon *f19 = f17->summonDemon();
    Demon *f20 = f17->summonDemon();
    Necromanser *f21 = new Necromanser("Negr");
    Necromanser *f22 = new Necromanser("Lich");

    SECTION("Priest test") {
        REQUIRE(f15->getDamage() == 20 );
        REQUIRE(f15->getHitPoints() == 150);
        
        f15->castSpell(f16, Fireball);
        f15->castSpell(f16, Fireball);
        
        REQUIRE(f16->getHitPoints() == 110);
        
        f15->castSpell(f16, Heal);
        
        REQUIRE(f16->getHitPoints() == 150);
        
        f15->attack(f16);
        
        REQUIRE(f16->getHitPoints() == 130);
        REQUIRE(f15->getHitPoints() == 140);
        REQUIRE(f15->getIsVampire() == false);
        REQUIRE(f16->getIsUndead() == false);
        REQUIRE(f15->getIsWolf() == false);
        REQUIRE(f15->getManaPoints() == 20);

        f12->turnInWerewolf(f15);

        f15->transformInToWolf();

        f16->castSpell(f15, Fireball);

        REQUIRE(f15->getHitPoints() == 185);

        f16->castSpell(test3, Fireball);

        REQUIRE(test3->getHitPoints() == 140);

        f16->attack(test3);
        
        REQUIRE(test3->getHitPoints() == 105);

        test3->attack(f16);
        
        REQUIRE(test3->getHitPoints() == 95);
    }

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

    SECTION("Warlock test") {
        REQUIRE(f17->getDamage() == 15 );
        REQUIRE(f17->getHitPoints() == 140);
        
        f17->castSpell(f18, Fireball);
        
        REQUIRE(f18->getHitPoints() == 100);
        
        f17->castSpell(f18, Heal);
        
        REQUIRE(f18->getHitPoints() == 122);
        
        f17->attack(f18);
        
        REQUIRE(f18->getHitPoints() == 107);
        REQUIRE(f17->getHitPoints() == 133);
        REQUIRE(f17->getIsVampire() == false);
        REQUIRE(f18->getIsUndead() == false);
        REQUIRE(f17->getIsWolf() == false);
        REQUIRE(f17->getManaPoints() == 35);

        // f17->summonDemon();

        SECTION("Soldiers test") {
            REQUIRE(f19->getDamage() == 35);
            REQUIRE(f19->getHitPoints() == 190);

            f19->attack(f20);

            REQUIRE(f19->getHitPoints() == 173);
            REQUIRE(f20->getHitPoints() == 155);
            REQUIRE(f19->getNickName() == "Part of Legion");

            f19->attack(test5); 

            REQUIRE(f19->getHitPoints() == 158);
            REQUIRE(test5->getHitPoints() == 165);
        }
    }

    SECTION("Necromanser test") {
        REQUIRE(f21->getDamage() == 20 );
        REQUIRE(f21->getHitPoints() == 140);
        
        f21->castSpell(f22, Fireball);
        
        REQUIRE(f22->getHitPoints() == 100);
        
        f21->castSpell(f22, Heal);
        
        REQUIRE(f22->getHitPoints() == 122);
        
        f21->attack(f22);
        
        REQUIRE(f22->getHitPoints() == 102);
        REQUIRE(f21->getHitPoints() == 130);
        REQUIRE(f21->getIsVampire() == false);
        REQUIRE(f22->getIsUndead() == true);
        REQUIRE(f21->getIsWolf() == false);
        REQUIRE(f21->getManaPoints() == 45);

        f21->attack(test5);
        // f21->attack(f22);
        // f21->attack(f22);
        // f21->attack(f22);
        // f21->attack(f22);
        // f21->attack(f22);

        // REQUIRE(f22->getHitPoints() == 0);
        REQUIRE(f21->getHitPoints() == 115);

        delete test5;
        
        REQUIRE(f21->getHitPoints() == 135);

    }
};
