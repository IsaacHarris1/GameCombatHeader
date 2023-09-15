#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <random>
#include <ctime>
#include <fstream>
#include "master.h"
#include "Enemies.h"
#include "utilities.h"
using namespace std;


//bool isAlive()
//edited for team creation and storing
void createEnemies(vector<Enemies>& enemyStatHolder){
    string name;
    int health;
    int roll;
    int initiativeModifier;
    int initiativeHolder;
    int armorClass;
    string inputs;
    
    cout << endl << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please enter enemy name" << endl;
    getline(cin, name);
    
    cout << "Please enter enemy health " << endl;
    health = inputValidation();
    
    cout << "Please enter the enemy intiative modifier" << endl;
    initiativeModifier = inputValidation();
    
    initiativeHolder = basicD20Roll() + initiativeModifier;
    
    cout << "Please enter the enemy armorClass" << endl;
    armorClass = inputValidation();
    
    enemyStatHolder.push_back(Enemies(name,health,armorClass,initiativeModifier,initiativeHolder));
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout << "if you are done please press d, or press c to add more foes!" << endl;
}


void createCharacter(vector<master>& playerStatHolder){
    string name;
    int health;
    int roll;
    int initiativeModifier;
    int armorClass;
    string inputs;
    
    cout << endl << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please enter player name" << endl;
    getline(cin, name);
    
    cout << "Please enter player health " << endl;
    health = inputValidation();
    
    cout << "Please enter the players intiative modifier" << endl;
    initiativeModifier = inputValidation();
    
    cout << "Please enter the players armorClass" << endl;
    armorClass = inputValidation();
    
    playerStatHolder.push_back(master(name,health,initiativeModifier,armorClass));
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout << "if you are done please press d, or press c to add more players!" << endl;
}
int main(){
  int selection = 0;
  string inputs = "a";
  vector<master> playerStatHolder;
  vector<Enemies> enemyStatHolder;
  vector<int> initiativeHolder;
  

while(true){
    cout << "Hello user, here are your options for the menu, select from the options below" << endl;
    cout << "1: Begin/Edit the party" << endl;
    cout << "2: Display the party" << endl;
    cout << "3: Begin/edit enemies" << endl;
    cout << "4: Display the enemies" << endl;
    cout << "5: Begin combat" << endl;
    cout << "6: Terminate program" << endl;

   int selection = inputValidation();
    
     if(selection == 1){
        bool editingParty = true;
        
        while(editingParty){
           cout << "Enter in player info, press d when prompted if done" << endl;
           createCharacter(playerStatHolder);   
        char userInput = inputCharValidation();
              if(userInput == 'd'){
                  cout << "done! \n";
                  editingParty = false;
                }
              else if(userInput == 'c'){
                   continue;
                }
            }
        }
        
    else if(selection == 2){
      
      if(playerStatHolder.size() == 0){
         // clearScreen();
          cout << "The party is currently empty, please press 1 to add" << endl;
          
      }
      else{
          for(int i = 0; i < playerStatHolder.size(); i++){
              cout << '\n';
              cout << "Name: " << playerStatHolder.at(i).getName() << endl;
              cout << "health: " << playerStatHolder.at(i).getHealth() << endl;
              cout << "modifier: " << playerStatHolder.at(i).getInitiativeModifier() << endl;
              cout << "Armor class: " << playerStatHolder.at(i).getArmorClass() << endl;
              cout << "\n";
          }
        }
    }
    
    else if(selection == 3){
        bool editingEnemies = true;
        if(enemyStatHolder.size() == 0){
          //  clearScreen();
            cout << "There are no enemies in this list, beginning list" << endl;
            
        }
        while(editingEnemies){
            cout << "Enter in enemy info, press d when prompted if done" << endl;
            createEnemies(enemyStatHolder);
        char userInput = inputCharValidation();
            if(userInput == 'd'){
                cout << "done! \n";
                editingEnemies = false;
            }
            else if(userInput == 'c'){
                continue;
            }
        }
        
    }
    
    else if(selection == 4){
        if(enemyStatHolder.size() == 0){
            //clearScreen();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "There are no enemies in this list" << endl;
        }
        else if(enemyStatHolder.size() > 0){
            for(int i = 0; i < enemyStatHolder.size(); i++){
                cout << "\n";
                cout << "Name: " << enemyStatHolder.at(i).getName() << endl;
                cout << "Health: " << enemyStatHolder.at(i).getHealth() << endl;
                cout << "Initiative: " << enemyStatHolder.at(i).getInitiativeHolder() << endl;
                cout << "Armor class: " << enemyStatHolder.at(i).getArmorClass() << endl << endl;
            }
        }
    }
    
    else if(selection == 5){
            cout << "combat selected" << endl;
            //combad code here
    }
    
    else if(selection == 6){
            cout << "Program terminated" << endl;
            break;
        }

}


 return 0;
 
}