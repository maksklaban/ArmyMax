#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../State/State.h"
#include "../exception.h"

class Unit {
    protected:
        State* state;
        std::string nickName;
    public:
        Unit(int damage, int hitPoints, std::string nickName, std::string title="Default");
        virtual ~Unit();
        
        const std::string& getNickName() const;
        const int getDamage() const;
        const int getHitPoints() const;
        const int getHitPointsLimit() const;
        const std::string& getTitle() const;
        const State& getState() const;
        
        void takeDamage(int dmg);
        void addHitPoints(int hp);
        
        virtual void attack(Unit* enemy) = 0;
        virtual void counterAttack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H
