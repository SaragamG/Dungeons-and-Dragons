// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Dungeon class

#ifndef DUNGEON_H
#define DUNGEON_H

#include <string>
#include <vector>
#include "Player.h"
#include "Monster.h"
#include "Inventory.h"
#include "Room.h"
#include "Merchant.h"
using namespace std;
class Dungeon
{
    public:
        Dungeon(); // set socercer anger level to 0
        void angerUp(); // increment sorcerer anger level by 2
        int getAnger(); // returned sorcerers anger level
        bool fightMonster(Inventory & inv, Monster & mon); // gives option of attacking or running away from fight
        bool attack(Inventory & inv, Monster & mon); // attacks monster using formula
        void surrender(Inventory & inv); // runs away from fight. loses one member
        void cook(Inventory & inv); // cooks food and gains fullness
        bool ncpPuzzle(Merchant & shop, Inventory & inv, Monster & mon); // non character players interaction
        bool doorPuzzle(Inventory & inv); // rock paper scissors
        void explore(Inventory & inv, Monster & mon, Room & r); //explores room trying to find key
        bool openDoor(Room & r, Inventory & inv); // opens door to next level
        void setPlayers(Player & play); // creates vector of Player objects
        void playerLost(string playername, Inventory & inv); // loses member
        int getNumPlayers(); // return number of players
        int statusUpdate(Room & r, Inventory & inv); // gives status of all items
        void foundKey(); // key is found
        void resetKey();
        bool getKey();
        void partyFullnessDrop(); // fullness of entire party drops
        string getRiddleQ(); // riddle questions
        string getRiddleA(); // answers
        void misfortune(Inventory & inv, Room & r); // misforutne if they land in a trap
        void misfortuneS(Inventory & inv); // misfortune if player get left behind
        void removeAllArmor(Inventory & inv); // removes all armor
        void checkFullness(Inventory & inv); // checking the fullness of the players
        
    private:
        int anger;
        vector<Player> players;
        int numPlayers;
        bool key;
        string riddleQ[7];
        string riddleA[7];
        int split(string text, char delimiter, string arr[], int size);
        int riddleCount;

};

#endif