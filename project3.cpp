// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Main Driver

#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.h"
#include "Inventory.h"
#include "Monster.h"
#include "Player.h"
#include "Room.h"
#include "Merchant.h"
using namespace std;

int main()
{
    Dungeon dun;
    Inventory inv;
    Monster mon;
    Room r;
    Merchant shop;
    Player leader, p2, p3, p4, p5;
    string playername;
    // creating vectors of Player objects in other classes
    dun.setPlayers(leader);
    dun.setPlayers(p2);
    dun.setPlayers(p3);
    dun.setPlayers(p4);
    dun.setPlayers(p5);
    shop.setPlayers(leader);
    shop.setPlayers(p2);
    shop.setPlayers(p3);
    shop.setPlayers(p4);
    shop.setPlayers(p5);
    // beginning of the game
    cout << "-----Welcome to the Dungeon!-----\nYou must make it through five rooms by buying goods, fighting monsters, and finding keys and various treasures along the way. You think you can survive the Dungeon?" << endl;    
    cout << "--Players--\nEnter your name: " << endl;
    cin >> playername;
    leader.setName(playername);
    cout << "Enter name of player 2: " << endl;
    cin >> playername;
    p2.setName(playername);
    cout << "Enter name of player 3: " << endl;
    cin >> playername;
    p3.setName(playername);
    cout << "Enter name of player 4: " << endl;
    cin >> playername;
    p4.setName(playername);
    cout << "Enter name of player 5: " << endl;
    cin >> playername;
    p5.setName(playername);
    //setting room names, treasure names, and monster names and levels
    r.setRoomName();
    r.setTreasureNames();
    mon.setMonsterName(r);
    mon.setMonsterLevel(r);
    cout << "Between the 5 of you, you have 100 gold coins. You will need to spend the rest of your money on the following items:\n" << endl;
    cout << "- INGREDIENTS. To make food, you have to cook raw ingredients.\n- COOKWARE. If you want to cook, you have to have cookware first.\n- WEAPONS. You’ll want at least one weapon per party member to fend off monsters.\n- ARMOR. Armor increases the chances of surviving a monster attack.\n";
    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. But beware, some of the merchants in this dungeon are shady characters, and they won’t always give you a fair price..." << endl;
    shop.market(inv);
    int option;
    bool open = false;
    do
    {
        do
        {
            option = dun.statusUpdate(r, inv);
            switch(option)
            {
                case 1:
                    dun.fightMonster(inv, mon);
                    break;
                case 2:
                    dun.ncpPuzzle(shop, inv, mon);
                    break;
                case 3:
                    dun.cook(inv);
                    break;
                case 4:
                    dun.explore(inv, mon, r);
                    break;
                case 5:
                    open = dun.openDoor(r, inv); 
                    break;
                case 6:
                    cout << "Oh no! You have failed to pass all the rooms. Come again to escape the dungeon!" << endl;
                    break;
                default:
                    cout << "Invalid input" << endl; 
                    break;
            }
        }
        while(open == false || option == 6); // once option is 6 (quit), loop ends
        r.levelUp();
        r.setRoomName();
        r.setTreasureNames();
        mon.setMonsterName(r);
        mon.setMonsterLevel(r);
        dun.resetKey();
    }
    while(option != 6 || dun.getNumPlayers() == 0 || dun.getAnger() == 100 || r.getLevel() == 5);
    if(dun.getNumPlayers() == 0)
    {
        cout << "OH NO! You all died in the dungeon. Better luck next time!" << endl;
    }
    else if(dun.getAnger() == 100)
    {
        cout << "OH NO! The sorcerer got too angry and killed you all! Better luck next time!" << endl;
    }
    else if(r.getLevel() == 6)
    {
        cout << "Congradulations! You have successfulling escaped the dungeon with:/n" << dun.getNumPlayers() << " players\n";
        cout << inv.getGold() << " pieces of gold\n" << endl;  
    }
            
    
    
}