#ifndef ENEMIES_H
#define ENEMIES_H

#include "master.h"

class Enemies : public master {
    public:
        Enemies(const std::string name, int health, const int armorClass, const int initiativeModifier, const int initiativeHolder);
        
        int getInitiativeHolder() const;
        
    private:
        int initiativeHolder;
};


#endif