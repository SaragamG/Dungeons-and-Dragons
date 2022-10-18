// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Player class

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;
class Player
{
    public:
        Player();
        void setName(string pname); // sets name
        string getName(); // return string anme
        void setWeapon(string pweapon); // sets weapon string name
        string getWeapon(); // return name of eewapon
        bool specialWeapon(); // checks if weapon is special
        void getArmor(); // returns number of armor
        bool checkArmor(); // checks if player has armor
        void addFullness(int pfullness); // adds fullness
        void fullnessUp(); // incremetns fullness
        void fullnessDown(); // decrements fullness
        int getFullness(); // reutrns fullness
        void removeArmor(); // removes armor
        
    private:
        string weapon;
        int fullness;
        int armor;
        string playerName;

};

#endif