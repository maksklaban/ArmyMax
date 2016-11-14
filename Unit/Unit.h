#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <../State/State.h>
#include <../exception.h>

class Unit : public State {
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
        void attack(Unit* enemy);
        void counterAttack(int dmg);
};

std::iostream& operator<<(std::iostream out, Unit& unit);

#endif // UNIT_H
