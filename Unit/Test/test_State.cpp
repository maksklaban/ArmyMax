#include "../Unit.h"
#include "catch.hpp"

TEST_CASE("test Unit class", "[Unit]") {
    Unit f1(20, 100, "Warrior");
    Unit f2(25, 90, "Knight");
    
    REQUIRE(f1.getDamage() == 20);
    REQUIRE(f1.getHitPoints() == 100);
    REQUIRE(f1.getHitPointsLimit() == 100);
    REQUIRE(f1.getTitle() == "Default");
    REQUIRE(f1.getNickName() == "Warrior");
    
    SECTION("take damage and add HP") {
        f1.takeDamage(20);
        
        REQUIRE(f1.getHitPoints() == 80);
        
        f1.takeDamage(79);
        
        REQUIRE(f1.getHitPoints() == 1);
        
        f1.addHitPoints(98);
        
        REQUIRE(f1.getHitPoints() == 99);
        
        f1.addHitPoints(99);
        
        REQUIRE(f1.getHitPoints() == 100);
        
        f1.attack(f2);
        
        REQUIRE(f1.getHitPoints() == 88);
        REQUIRE(f2.getHitPoints() == 80);
        
        f2.attack(f1);
        
        REQUIRE(f1.getHitPoints() == 63);
        REQUIRE(f2.getHitPoints() == 70);
        
    }
    
}
