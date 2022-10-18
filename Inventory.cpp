// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Inventory class - Function Implementations

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#include "Inventory.h"

// functions defined here

Inventory::Inventory()
{
    ingredients = 0;
    gold = 100;
    weapons = 0;
    armor = 0;
    specialWeapon = 0;
}

void Inventory::addIngredients(int pindgred)
{
    ingredients = ingredients + pindgred;
}

void Inventory::setIngredients(int pindgred)
{
    ingredients = pindgred;
}

void Inventory::resetIngredients()
{
    ingredients = 0;
}

int Inventory::getIngredients()
{
    return ingredients;
}

void Inventory::addCookware(string pcookware)
{
    cookware.push_back(pcookware);
}

void Inventory::resetCookware()
{
    cookware.clear();
}

vector<string> Inventory::getCookware()
{
    return cookware;
}

void Inventory::addGold(int pgold)
{
    gold = gold + pgold;
}

void Inventory::setGold(int pgold)
{
    gold = pgold;
}

int Inventory::getGold()
{
    return gold;
}

void Inventory::weaponsUp()
{
    weapons++;
}

void Inventory::weaponsDown()
{
    weapons--;
}

int Inventory::getNumWeapons()
{
    return weapons;
}

void Inventory::addArmor(int parmor)
{
    armor = armor + parmor;
}

void Inventory::armorUp()
{
    armor++;
}

void Inventory::armorDown()
{
    armor--;
}

void Inventory::resetArmor()
{
    armor = 0;
}

int Inventory::getNumArmor()
{
    return armor;
}

void Inventory::addSpecialWeapon()
{
    specialWeapon++;
}

int Inventory::getSpecialWeapon()
{
    return specialWeapon;
}

void Inventory::addTreasures(string treas)
{
    treasures.push_back(treas);
}

vector<string> Inventory::getTreasures()
{
    return treasures;
}