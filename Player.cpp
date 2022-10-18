// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Player class - Function Implementations

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#include "Player.h"
#include "Inventory.h"

// functions defined here

Player::Player()
{
    weapon = "";
    fullness = 10;
    armor = 0;
    playerName = "";
}

void Player::setName(string pname)
{
    playerName = pname;
}

string Player::getName()
{
    return playerName;
}

void Player::setWeapon(string pweapon)
{
    weapon = pweapon;
}

bool Player::specialWeapon()
{
    bool checkWeapon = false;
    if(weapon == "crossbow" || weapon == "battle-axe" || weapon == "longsword")
    {
        checkWeapon = true;
    }
    return checkWeapon;
}

string Player::getWeapon()
{
    return weapon;
}

void Player::getArmor()
{
    armor = 1;
}

bool Player::checkArmor()
{
    bool checkArm = false;
    if(armor == 1)
    {
        checkArm = true;
    }
    return checkArm;
}

void Player::addFullness(int pfullness)
{
    fullness = fullness + pfullness;
}

void Player::fullnessUp()
{
    fullness++;
}

void Player::fullnessDown()
{
    fullness--;
}

int Player::getFullness()
{
    return fullness;
}

void Player::removeArmor()
{
    armor = 0;
}