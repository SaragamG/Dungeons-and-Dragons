// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Merchant class - Function Implementations

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Merchant.h"
#include "Inventory.h"
#include "Player.h"
// functions defined here

Merchant::Merchant()
{
    weaponsPrice[0] = 2;
    weaponsPrice[1] = 2;
    weaponsPrice[2] = 5;
    weaponsPrice[3] = 5;
    weaponsPrice[4] = 5;
    cookwarePrice[0] = 20;
    cookwarePrice[1] = 10;
    cookwarePrice[2] = 5;
    armorPrice = 5;
    ingredientPrice = 1;
}

void Merchant::setPlayers(Player & play)
{
    players.push_back(play);
}

void Merchant::market(Inventory & inv) // displays items to buy and prices
{
    int menu;
    int subMenu;
    int kilo;
    int numArmor;
    int newGold;
    int count = 0;
    do
    {
        cout << "------Market------\n1. Ingredients\n2. Weapons\n3. Armor\n4. Cookware\n5. Exit" << endl;
        cin >> menu;
        switch(menu)
        {
            case 1:
                cout << "Input how many kilograms of ingredients you would like to purchase. I recommend atleast 10 kg of ingredients per person. Each kilogram is " << ingredientPrice << "gold piece.\nKilograms:" << endl;
                cin >> kilo;
                if(inv.getGold() < (kilo * ingredientPrice))
                {
                    cout << "You don't have enough gold to purhcase this quantity." << endl;
                }
                else
                {
                    inv.addIngredients(kilo);
                    newGold = inv.getGold() - (kilo * ingredientPrice);
                    inv.setGold(newGold);
                }
                break;
            case 2:
                do
                {
                    cout << "Select number corresponding to the weapon of your liking. You can have a max of 1 weapon per person and buying upgraded weapons that are worth 5 gold pieces will maximize your chances of surival during an attack. Here are the options:\n1. A club - " << weaponsPrice[0];
                    cout << " gold pieces\n2. A spear - " << weaponsPrice[1] << " gold pieces\n3. A crossbow - " << weaponsPrice[2] << " gold pieces\n4. A battle-axe - " << weaponsPrice[3] <<  " gold pieces\n5. A longsword - " << weaponsPrice[4] << " gold pieces\n6. Go back" << endl;
                    cin >> subMenu;
                    switch(subMenu)
                    {
                        case 1:
                            if(inv.getGold() < weaponsPrice[0])
                            {
                                cout << "You don't have enough gold to purchase this item." << endl;
                            }
                            else
                            {
                                players[count].setWeapon("club");
                                inv.weaponsUp();
                                newGold = inv.getGold() - weaponsPrice[0];
                                inv.setGold(newGold);
                                count++;
                            }
                            break;
                        case 2:
                            if(inv.getGold() < weaponsPrice[1])
                            {
                                cout << "You don't have enough gold to purchase this item." << endl;
                            }
                            else
                            {    
                                players[count].setWeapon("spear");
                                inv.weaponsUp();
                                newGold = inv.getGold() - weaponsPrice[1];
                                inv.setGold(newGold);
                                count++;
                            }
                            break;
                        case 3:
                            if(inv.getGold() < weaponsPrice[2])
                            {
                                cout << "You don't have enough gold to purchase this item." << endl;
                            }
                            else
                            {
                                players[count].setWeapon("crossbow");
                                inv.weaponsUp();
                                newGold = inv.getGold() - weaponsPrice[2];
                                inv.setGold(newGold);
                                inv.addSpecialWeapon();
                                count++;
                            }
                            break;
                        case 4:
                            if(inv.getGold() < weaponsPrice[3])
                            {
                                cout << "You don't have enough gold to purchase this item." << endl;
                            }
                            else
                            {
                                players[count].setWeapon("battle-axe");
                                inv.weaponsUp();
                                newGold = inv.getGold() - weaponsPrice[3];
                                inv.setGold(newGold);
                                inv.addSpecialWeapon();
                                count++;
                                break;
                            }
                        case 5:
                            if(inv.getGold() < weaponsPrice[4])
                            {
                                cout << "You don't have enough gold to purchase this item." << endl;
                            }
                            else
                            {
                                players[count].setWeapon("longsword");
                                inv.weaponsUp();
                                newGold = inv.getGold() - weaponsPrice[4];
                                inv.setGold(newGold);
                                inv.addSpecialWeapon();
                                count++;
                            }
                            break;
                        case 6:
                            continue;
                        default:
                            cout << "Invalid input. Choose from the following items only." << endl;
                            break;
                    }
                }
                while(subMenu != 6);
                break;
            case 3:
                cout << "Equipping your team with the maximum amount of armor (1 per person) will maximum amount will not increase your chances further. A set of armor costs " << armorPrice << " gold coins.\n# of armor:" << endl;
                cin  >> numArmor;
                if(inv.getGold() < (numArmor * armorPrice))
                {
                    cout << "You don't have enough gold to purchase this quantity." << endl;
                }
                else if(inv.getNumArmor() + numArmor > 5)
                {
                    cout << "You can't exceed the maximum number of armor (5)." << endl;
                }
                else
                {
                    inv.addArmor(numArmor);
                    for(int i = 0; i < numArmor; i++)
                    {
                        players[i].getArmor();
                    }
                }
                break;
            case 4:
                do
                {
                    cout << "1. Cauldron - " << cookwarePrice[0] << " gold pieces. It is made of thick sturdy metal, so it only has a 2% chance of breaking each time you use it.\n2. Cast Iron - " << cookwarePrice[1] << " gold pieces.";
                    cout << "You can use a frying pan to sizzle ingredients. It is not as sturdy as a cauldron, with a 10% chance ofbreaking each time you use it.\n3. Ceramic Pot - " << cookwarePrice[2] << " gold pieces.";
                    cout << "You can use a ceramic pot to stew and boil ingredients. It is made from weaker material, so it has a 25% chance of breaking each time you use it.\nYou can have multiple cookwares.\nSelect number corresponding to the cookware of your liking:\n4. Go back" << endl;
                    cin >> subMenu;
                    switch(subMenu)
                    {
                        case 1:
                            if(inv.getGold() < cookwarePrice[0])
                            {
                                cout << "You don't have enough gold to purchase this item." << endl;
                            }
                            else
                            {
                                inv.addCookware("Cauldron");
                                newGold = inv.getGold() - cookwarePrice[0];
                                inv.setGold(newGold);
                            }
                            break; 
                        case 2:
                            if(inv.getGold() < cookwarePrice[1])
                            {
                                cout << "You don't have enough gold to purchase this item." << endl;
                            }
                            else
                            {
                                inv.addCookware("Cast Iron");
                                newGold = inv.getGold() - cookwarePrice[1];
                                inv.setGold(newGold);
                            }
                            break; 
                        case 3:
                            if(inv.getGold() < cookwarePrice[2])
                            {
                                cout << "You don't have enough gold to purchase this item." << endl;
                            }
                            else
                            {
                                inv.addCookware("Ceramic Pot");
                                newGold = inv.getGold() - cookwarePrice[2];
                                inv.setGold(newGold);
                            }
                            break; 
                        default:
                            cout << "Invalid input. Choose from the following items only." << endl;
                            break;
                    }
                }
                while(subMenu != 4);
                break;
            case 5:
                cout << "All set to go!" << endl;
        }
    }
    while(menu != 5);
}

void Merchant::pricesUp() // increases prices by 25% 
{
    for(int i = 0; i < 5; i++)
    {
        weaponsPrice[i] = weaponsPrice[i] + (weaponsPrice[i] / 4);
    }
    for(int x = 0; x < 3; x++)
    {
        cookwarePrice[x] = cookwarePrice[x] +(cookwarePrice[x] / 4);
    }
    armorPrice = armorPrice + (armorPrice / 4);
    ingredientPrice = ingredientPrice + (ingredientPrice / 4);
}