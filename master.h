#ifndef MASTER_H
#define MASTER_H
#include <string>



class master{
    public:
        master(const std::string name, const int health, const int initiativeModifier, const int armorClass);
        
        void editHealth(int newHealth);
        std::string getName() const;
        int getHealth() const;
        int getInitiativeModifier() const;
        int getArmorClass() const;
        
    private:
        std::string name;
        int health;
        int initiativeModifier;
        int armorClass;
        
};

#endif