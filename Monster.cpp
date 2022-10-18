// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Monster class - Function Implementations

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Monster.h"

// functions defined here

Monster::Monster() // set monster name to nothing and level to 0
{
    for(int i = 0; i < 4; i++)
    {
        monsterName[i] = "";
    }
    monsterLevel = 0;
}

string Monster::getMonsterName(int ind) // return name of monster
{
    return monsterName[ind];
}

void Monster::setMonsterName(Room & r) // set name of monster to given string
{
    if(r.getLevel() == 1)
    {
        monsterName[0] = "Animated armor";
        monsterName[1] = "Bugbear";
        monsterName[2] = "Harpy";
        monsterName[3] = "Scarecrow";
    }
    else if(r.getLevel() == 2)
    {
        monsterName[0] = "Minotaur";
        monsterName[1] = "Owlbear";
        monsterName[2] = "Banshee";
        monsterName[3] = "Wereboar";
    }
    else if(r.getLevel() == 3)
    {
        monsterName[0] = "Giant crocodile";
        monsterName[1] = "Troll";
        monsterName[2] = "Hobgoblin warlord";
        monsterName[3] = "Mammoth";

    }
    else if(r.getLevel() == 4)
    {
        monsterName[0] = "Stone giant";
        monsterName[1] = "Night hag";
        monsterName[2] = "Assassin";
        monsterName[3] = "Hydra";

    }
    else if(r.getLevel() == 5)
    {
        monsterName[0] = "Cloud giant";
        monsterName[1] = "Silver dragon";
        monsterName[2] = "Vampire";
        monsterName[3] = "Lich";
    }
}

int Monster::getMonsterLevel() // return monsters level
{
    return monsterLevel;
}

void Monster::setMonsterLevel(Room & r) // set monsters level to given integer
{
    monsterLevel = r.getLevel();
}