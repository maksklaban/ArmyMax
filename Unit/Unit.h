#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../State/State.h"
#include "../exception.h"
#include "Ability.h"
#include "Observer.h"
#include "Subject.h"

class Unit : public Ability, public Observer, public Subject {
    protected:
        State* state;
        State* wolfState;
        State* normalState;
        std::string nickName;
        bool isUndead;
        
    public:
        Unit(std::string nickName, int damage, int hitPoints, std::string title="Default", bool isUndead=false, bool isVampire=false, bool isWerewolf=false);
        virtual ~Unit();
        
        const std::string& getNickName() const;
        const int getDamage() const;
        const int getHitPoints() const;
        const int getHitPointsLimit() const;
        const bool getIsUndead() const;
        const bool getIsWolf() const;
        const std::string& getTitle() const;
        const State& getState() const;
        
        virtual void takeMagDamage(int dmg);
        void takePhysicalDamage(int dmg);
        virtual void addHitPoints(int hp);
        
        virtual void transformInToWolf();
        virtual void transformBack();
        void vampireAttack(Unit* enemy);
        virtual void turnInVampire(Unit* enemy);
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H
