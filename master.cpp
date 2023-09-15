#include "master.h"

master::master(const std::string name, int health, const int initiativeModifier, const int armorClass)
 : name(name), health(health), initiativeModifier(initiativeModifier), armorClass(armorClass) {}
 
 void master::editHealth(int newHealth){
     health = newHealth;
 }
 
 std::string master::getName() const {
     return name;
 }
 
 int master::getHealth() const {
     return health;
 }
 
 int master::getInitiativeModifier() const {
     return initiativeModifier;
 }
 
 int master::getArmorClass() const {
     return armorClass;
 }
