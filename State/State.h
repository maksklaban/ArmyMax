#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <../exception.h>

class State {
    protected:
        int hitPoints;
        int hitPointsLimit;
        int damage;
        std::string nickName;
        
        void ensureIsAlive();
    
    public:
        State(int hitPoints, int damage, std::string nickName);
        virtual ~State();
        
        const int getHitPoints() const;
        const int getHitPoints() const;
        const int getHitPointsLimit() const;
        const int getDamage() const;
        const std::string getNickName() const;
        
        void addHitPoints(int hp);
        void takeDamage(int dmg);
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif // STATE_H
