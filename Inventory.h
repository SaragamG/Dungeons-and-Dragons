// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Inventory class

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
using namespace std;
class Inventory
{
    public:
        Inventory();
        void addIngredients(int pindgred); // adds ingredients
        void setIngredients(int pindgred); // sets ingrredients to certain number
        void resetIngredients(); // resets ingredients to 0
        int getIngredients(); // returns number of ingredients
        void addCookware(string pcookware); // add cookware to vectorf
        void resetCookware(); // clears vector
        vector<string> getCookware(); // returns cookare vector
        void addGold(int pgold); // adds gold
        void setGold(int pgold); // sets gold to given number
        int getGold(); // returns number of gold
        void weaponsUp(); // increments weapons
        void weaponsDown(); // decrements number of weapons
        int getNumWeapons(); // returns number of weapons
        void addArmor(int parmor); // adds armor
        void armorUp(); // increments armor
        void armorDown(); // decrements armor
        void resetArmor(); // resets armor to 0
        int getNumArmor(); // return number of armor
        void addSpecialWeapon(); // increments special weapons
        int getSpecialWeapon(); // reuturns number of special weapons
        void addTreasures(string treas); // adds reasure name to vector
        vector<string> getTreasures(); // return treasure vector

    private:
        int ingredients;
        vector<string> cookware;
        int weapons;
        int armor;
        int specialWeapon;
        int gold;
        vector<string> treasures;
};

#endif