// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Dungeon class - Function Implementations

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "Dungeon.h"
#include "Player.h"
#include "Monster.h"
#include "Inventory.h"
#include "Room.h"
#include "Merchant.h"

// functions defined here

Dungeon::Dungeon() // set socercer anger level to 0
{
    anger = 0;
    numPlayers = 5;
    key = false;
    riddleCount = 0;
    ifstream file;
    string line;
    string arr[2];
    file.open("riddles.txt");
    if(file.is_open())
    {
        while(getline(file, line))
        {
            int i = 0;
            if(!line.empty()) // storing each value from line into respective product array indexes
            {
                split(line, ':', arr, 2);
                riddleQ[i] = arr[0];
                riddleA[i] = arr[1];
                i++;
            }
        }
    }
}

void Dungeon::angerUp() // increment sorcerer anger level by 2
{
    anger = anger + 2;
}

int Dungeon::getAnger()
{
    return anger;
}

bool Dungeon::fightMonster(Inventory & inv, Monster & mon)
{
    bool win = false;
    int choice;
    srand(time(NULL));
    int r1 = rand() % 3;
    cout << mon.getMonsterName(r1) << " ahead! They look hostile!\nDo you want to 1. Attack 2. Surrender" << endl;
    cin >> choice;
    if(choice == 1)
    {
        attack(inv, mon);
    }
    else if(choice == 2)
    {
        surrender(inv);
    }
    return win;
}

bool Dungeon::attack(Inventory & inv, Monster & mon)
{
    srand(time(NULL));
    bool win = false;
    int w = inv.getNumWeapons() + inv.getSpecialWeapon();
    int a = inv.getNumArmor();
    int c = mon.getMonsterLevel();
    int r1 = rand() % 6 + 1;
    int r2 = rand() % 6 + 1;
    int result = (r1 * w) - (r2 * c * (1 / a));
    if(result > 0)
    {
        // if win, player gets 50 gold and 20 kg food
        cout << "You have defeated the monster. 50 gold pieces and 20 kg of ingredients have been added to your inventory!" << endl;
        inv.addGold(50);
        inv.addIngredients(20);
        win = true;
        int r3 = rand() % 4;
        if(r3 == 1)
        {
            cout << "The monster has dropped the key to the room! Key has been added to your inventory." << endl;
            key = true;
        }
    }
    else if(result <= 0)
    {
        // if lose, player loses member and gets some food taken away
        cout << "Oh no! You have been defeated! The monster has taken a quarter of your gold reserves and 30 kg of ingredients!" << endl;
        int newGold = inv.getGold() - (inv.getGold() / 4);
        inv.setGold(newGold);
        int newIngred = inv.getIngredients() - 30;
        inv.setIngredients(newIngred);
        int r4 = rand() % 10;
        if(r4 == 4)
        {
            int r5 =rand() % getNumPlayers() + 1;
            cout << "One of your party members has been defeated in battle! All their epuipment(armor) has been dropped as well. May be rest in peace." << endl;
            playerLost(players[r5].getName(), inv);
        }
    }
    partyFullnessDrop();
    angerUp();
    checkFullness(inv);
    return win;
}

void Dungeon::surrender(Inventory & inv)
{
    srand(time(NULL));
    int r1 = rand() % getNumPlayers() + 1;
    cout << "Unfortunetly, your teammate " << players[r1].getName() << " was unable to escape the wrath of the monster and is held captive. You must leave them behind and continue on your journey." << endl;
    playerLost(players[r1].getName(), inv);
    angerUp();
}

void Dungeon::cook(Inventory & inv)
{
    int choice;
    int kilo;
    cout << "Which cookware would you like to use?\n1. Cauldron\n2. Cast Iron\n3. Ceramic Pot" << endl;
    cin >> choice;
    if(choice == 1 || choice == 2 || choice == 3)
    {
        cout << "Every 5 kilograms of ingredients increases everyone's fullness by 1.\nHow many kilograms do you want to cook?" << endl;
        cin >> kilo;
        int newIngred = inv.getIngredients() - kilo;
        inv.setIngredients(newIngred);
        int full = kilo / 5;
        for(int i = 0; i < numPlayers; i++)
        {
            players[i].addFullness(full);
        }
    }
    else
    {
        cout << "Invalid input" << endl;
    }
    angerUp();
}

bool Dungeon::ncpPuzzle(Merchant & shop, Inventory & inv, Monster & mon)
{
    bool win = false;
    string answer;
    srand(time(NULL));
    int r1 = rand() % 3 + 1;
    if(r1 == 1)
    {
        cout << "You have chosen to speak to the NPC! The NPC prompts you with the following riddle:" << endl;
        cout << getRiddleQ() << endl;
        cin >> answer;
        if(answer == getRiddleA())
        {
            win = true;
            cout << "You have answered correctly. You have encountered a friendly merchant.\nThe friendly merchant offers the following:" << endl;
            shop.market(inv);
        }
        riddleCount++;
    }
    else if(r1 == 2)
    {
        win = true;
        cout << "You have chosen to speak to the NPC! The NPC prompts you with the following riddle:" << endl;
        cout << getRiddleQ() << endl;
        cin >> answer;
        if(answer == getRiddleA())
        {
            cout << "You have answered correctly. You have encountered a neutral merchant." << endl;
        }
        riddleCount++;
    }
    else if(r1 == 3)
    {
        cout << "OH NO! This NPC is evil, you must fight a monster to escape him!" << endl;
        fightMonster(inv, mon);
        riddleCount++;    
    }
    angerUp();
    return win;
}

bool Dungeon::doorPuzzle(Inventory & inv)
{
    srand(time(NULL));
    int r1 = rand() % 3 + 1;
    int choice;
    bool win = false;
    int count = 0;
    string name;
    cout << "OH NO! You've fallen into a trap! You must beat the door in a game of rock-paper-scissors! You have three tries to win or else one of your teammates die!";
    do
    {
        cout << "Choose wisely:\n1. Rock\n2. Paper\n3. Scissors" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1: 
                if(r1 == 3)
                {
                    win = true;
                }
                else if(r1 == 1)
                {
                    continue;
                }
                else
                {
                    count++;
                }
                break;
            case 2:
                if(r1 == 1)
                {
                    win = true;
                }
                else if(r1 == 1)
                {
                    continue;
                }
                else
                {
                    count++;
                }
                break;
            case 3:
                if(r1 == 2)
                {
                    win = true;
                }
                else if(r1 == 1)
                {
                    continue;
                }
                else
                {
                    count++;
                }
                break;
            default:
                cout << "Invalid input. Choose a number from 1 to 3." << endl;
                break;
        }
        if(count > 3)
        {
            int r2 = rand() % getNumPlayers() + 1;
            name = players[r2].getName();
            playerLost(players[r2].getName(), inv);
            win = true;
        }
    }
    while(win == false);
    if(count > 3)
    {
        cout << "OH NO! Your three tries are up and now your teammate " << name << " is dead. Come back again with the key!" << endl;
        win = false;
    }
    else
    {
        cout << "Nice work! Come back to the door with the key to not fall into another trap!" << endl;
    }
    angerUp();
    return win;
}

void Dungeon::explore(Inventory & inv, Monster & mon, Room & r)
{
    srand(time(NULL));
    int r1 = rand() % 5 + 1;
    if(r1 == 1)
    {
        cout << "After a close inspection of the room, your party as found the key!" << endl;
        foundKey();
    }
    else if(r1 == 2)
    {
        fightMonster(inv, mon);
    }
    else if(r1 == 3)
    {
        int r2 = rand() % 2;
        if(isdigit(r.getTreasureName(r2)[0]))
        {
            if(r.getLevel() == 1)
            {
                inv.addGold(50);
            }
            else if(r.getLevel() == 2)
            {
                inv.addGold(100);
            }
            else if(r.getLevel() == 3)
            {
                inv.addGold(500);
            }
            else if(r.getLevel() == 4)
            {
                inv.addGold(1000);
            }
            else if(r.getLevel() == 5)
            {
                inv.addGold(5000);
            }
        }
        else
        {
            inv.addTreasures(r.getTreasureName(r2));
        }
    }
    partyFullnessDrop();
    checkFullness(inv);
    angerUp();
}

bool Dungeon::openDoor(Room & r, Inventory & inv)
{
    bool open = false;
    if(getKey() == true)
    {
        srand(time(NULL));
        int r1 = rand() % 3 + 1;
        if(r1 == 1)
        {
            cout << "You have opened the door!" << endl;
            open = true;
        }
        else if(r1 == 2)
        {
            misfortune(inv, r);
        }
        else if(r1 == 3)
        {
            misfortuneS(inv);
        }
    }
    else if(getKey() == false)
    {
        doorPuzzle(inv);
    }
    angerUp();
    return open;
}

void Dungeon::setPlayers(Player & play)
{
    players.push_back(play);
}

void Dungeon::playerLost(string playername, Inventory & inv)
{
    for(int i = 0; i < players.size(); i++)
    {
        if(players[i].getName() == playername)
        {
            players.erase(players.begin() + (i - 1));
            if(players[i].checkArmor() == true)
            {
                inv.armorDown();
            }
        }
    }
    numPlayers--;
}

int Dungeon::getNumPlayers()
{
    return numPlayers;
}

int Dungeon::statusUpdate(Room & r, Inventory & inv)
{
    int option;
    cout << "----STATUS UPDATE----\nCURRENT ROOM: " << r.getRoomName() << endl;
    cout << "ROOM KEY FOUND: ";
    if(getKey() == true)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    cout << "SORCERER ANGER LEVEL: " << anger << " out of 100\n" << endl;
    cout << "----PARTY MEMBERS----" << endl;
    cout << "(Leader) Me: " << players[0].getFullness() << " fullness points" << endl;
    for(int i = 1; i < numPlayers; i++)
    {
        cout << players[i].getName() << ": " << players[i].getFullness() << " fullness points" << endl;
    }
    cout << endl;
    cout << "----MATERIALS----" << endl;
    cout << "INGREDIENTS: " << inv.getIngredients() << " kg" << endl;
    vector<string> cookware = inv.getCookware();
    int cauldron = 0;
    int cast = 0;
    int ceramic = 0;
    for(int i = 0; i < cookware.size(); i++)
    {
        if(cookware[i] == "Cauldron")
        {
            cauldron++;
        }
        else if(cookware[i] == "Cast Iron")
        {
            cast++;
        }
        else if(cookware[i] == "Ceramic Pot")
        {
            ceramic++;
        }
    }
    cout << "COOKWARE: " << cauldron << " Cauldron(s), " << cast << " Cast Iron Pan(s), " << ceramic << " Ceramic Pot(s)" << endl;
    cout << "ARMOR: " << inv.getNumArmor() << " set(s)" << endl;
    cout << "GOLD: " << inv.getGold() << " pieces" << endl;
    vector<string> treasures = inv.getTreasures();
    cout << "TREASURE ITEMS: ";
    if(treasures.size() > 0)
    {
        for(int i = 0; i < treasures.size(); i++)
        {
            cout << treasures[i] << ", ";
        }
    }
    else
    {
        cout << "" << endl;
    }
    cout << "Would you like to:\n1. Fight a monster\n2. Speak to NPC\n3. Cook & Eat\n4. Explore The Room\n5. Open The Door\n6. Quit" << endl;
    cin >> option;
    return option;
}

void Dungeon::foundKey()
{
    key = true;
}

void Dungeon::resetKey()
{
    key = false;
}

bool Dungeon::getKey()
{
    return key;
}

void Dungeon::partyFullnessDrop()
{
    for(int i = 0; i < players.size(); i++)
    {
        players[i].fullnessDown();
    }
}

string Dungeon::getRiddleQ()
{
    return riddleQ[riddleCount];
}

string Dungeon::getRiddleA()
{
    return riddleA[riddleCount];
}

int Dungeon::split(string text, char delimiter, string arr[], int size)
{
    int x = 0;
    int pos = 0;
    int length = text.length();
    if(text.length() == 0)
    {
        return 0;
    }
    for(int i = 0; i < length; i++) // looping to find delimiter
    { 
        if(text[i] == delimiter) // when delimiter is found
        {
            int m = i - pos;
            arr[x] = text.substr(pos, m);
            pos = i  + 1;
            x++;
        }
        else if(i == length - 1) // when the end of the text is reached
        {
            arr[x] = text.substr(pos, length);
        }
    }
    int numSplit = x + 1;
    if(numSplit > size) // if the number of splits is larger than the size of array, return -1.
    {
        return -1;
    }
    else
    {
        return numSplit;
    }
}

void Dungeon::misfortune(Inventory & inv, Room & r)
{
    srand(time(NULL));
    int r1 = rand() % 3 + 1;
    if(r1 == 1)
    {
        int r2 = rand() % 3 + 1;
        if(r2 == 1)
        {
            cout << "OH NO! Your team was robbed by dungeon bandits! You have no armor left!" << endl;
            removeAllArmor(inv);
        }
        else if(r2 == 2)
        {
            cout << "OH NO! Your team was robbed by dungeon bandits! You have no food left!" << endl;
            inv.resetIngredients();
        }
        else if(r2 == 3)
        {
            cout << "OH NO! Your team was robbed by dungeon bandits! You have no cookware left!" << endl;
            inv.resetCookware();
        }
    }
    else if(r1 == 2)
    {
        for(int i = 0; i < players.size(); i++)
        {
            if(players[i].getFullness() == 0)
            {
                playerLost(players[i].getName(), inv);
                cout << "OH NO! " << players[i].getName() << " has died of hunger!\nYour party size has reduced to " << getNumPlayers() << " members." << endl;
            }
        }
    }
    else if(r1 == 3)
    {
        int r3 = rand() % 2 + 1;
        {
            if(r3 == 1)
            {
                cout << "OH NO! One of your weapons broke!" << endl;
                players[0].setWeapon("");
                inv.weaponsDown();
            }
            else if(r3 == 2)
            {
                cout << "OH NO! One of your armor broke!" << endl;
                players[0].removeArmor();
                inv.armorDown();
            }
        }
    }
    angerUp();
}

void Dungeon::misfortuneS(Inventory & inv)
{
    srand(time(NULL));
    int r1 = rand() % getNumPlayers() + 1;
    cout << "OH NO! Your teammate " << players[r1].getName() << " is trapped in the previous room, and is unable to get through. You must continue without him.";
    playerLost(players[r1].getName(), inv);
    cout << "Your party size has reduced to " << getNumPlayers() << " members." << endl;
    angerUp();
}

void Dungeon::removeAllArmor(Inventory & inv)
{
    for(int i = 0; i < players.size(); i++)
    {
        players[i].removeArmor();
    }
    inv.resetArmor();
}

void Dungeon::checkFullness(Inventory & inv)
{
    for(int i = 0; i < numPlayers; i++)
        {
            if(players[i].getFullness() <= 0)
            {
                playerLost(players[i].getName(), inv);
            }     
        }
}