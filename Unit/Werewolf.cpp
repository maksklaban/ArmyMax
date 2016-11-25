#include "Werewolf.h"

Werewolf::Werewolf(std::string nickName, int damage, int hitPoints, std::string title) : Unit(nickName,damage, hitPoints, title, false, false, true) {}

Werewolf::~Werewolf() {}

void Werewolf::transformInToWolf() {
    this->state = this->wolfState;
}

void Werewolf::transformBack() {
    this->state = this->normalState;
}