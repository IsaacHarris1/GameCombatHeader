#include "Enemies.h"

Enemies::Enemies(const std::string name, int health, const int armorClass, const int initiativeModifier, const int initiativeHolder)
    : master(name, health, initiativeModifier, armorClass), initiativeHolder(initiativeHolder) {}
    
int Enemies::getInitiativeHolder() const {
    return initiativeHolder;
}