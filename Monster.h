// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Monster class

#ifndef MONSTER_H
#define MONSTER_H

#include <string>
using namespace std;
#include "Room.h"
class Monster
{
    public:
        Monster(); // set monster name to nothing and level to 0
        string getMonsterName(int ind); // return name of monster
        void setMonsterName(Room & r); // set name of monster to given string
        int getMonsterLevel(); // return monsters level
        void setMonsterLevel(Room & r); // set monsters level to given integer
        
    private:
        string monsterName[4];
        int monsterLevel;
        
};

#endif