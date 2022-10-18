// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Merchant class

#ifndef MERCHANT_H
#define MERCHANT_H

#include <string>
#include <vector>
using namespace std;
#include "Inventory.h"
#include "Player.h"
class Merchant
{
    public:
        Merchant(); // sets prices to the prices at the beginning of the game
        void setPlayers(Player & play); // creates a vector players
        void market(Inventory & inv); // displays items to buy and prices
        void pricesUp(); // increases prices by 25% 
        
    private:
        int weaponsPrice[5];
        int cookwarePrice[3];
        int armorPrice;
        vector<Player> players;
        int ingredientPrice;

};

#endif