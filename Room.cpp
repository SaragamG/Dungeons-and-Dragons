// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Room class - Function Implementations

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Room.h"

// functions defined here

Room::Room() // set room name to Red room , and treasure to stuff in red room
{
    roomName = "";
    for(int i = 0; i < size; i++)
    {
        treasure[i] = "";
    }
    level = 1;
}

string Room::getRoomName() // return room name
{
    return roomName;
}

void Room::setRoomName() // set name of room to given string
{
    if(getLevel() == 1)
    {
        roomName = "Red Room";
    }
    else if(getLevel() == 2)
    {
        roomName = "Blue Room";
    }
    else if(getLevel() == 3)
    {
        roomName = "Green Room";
    }
    else if(getLevel() == 4)
    {
        roomName = "Yellow Room";
    }
    else if(getLevel() == 5)
    {
        roomName = "Final Room";
    }
}

string Room::getTreasureName(int ind) //return names of treasures in the room
{
    return treasure[ind];
}

void Room::setTreasureNames() // set names of treasure into array of strings
{
    if(getLevel() == 1)
    {
        treasure[0] = "Quartz";
        treasure[1] = "Embroidered silk handkercheif";
        treasure[2] = "50 gold";
    }
    else if(getLevel() == 2)
    {
        treasure[0] = "Pearl";
        treasure[1] = "Bronze crown";
        treasure[2] = "100 gold";
    }
    else if(getLevel() == 3)
    {
        treasure[0] = "Topaz";
        treasure[1] = "Gold dragon comb";
        treasure[2] = "500 gold";
    }
    else if(getLevel() == 4)
    {
        treasure[0] = "Emerald";
        treasure[1] = "Old masterpiece painting";
        treasure[2] = "1000 gold";
    }
    else if(getLevel() == 5)
    {
        treasure[0] = "Diamond";
        treasure[1] = "Golden sarcophagus";
        treasure[2] = "5000 gold";
    }
}

int Room::getLevel() // return level number
{
    return level;
}

void Room::levelUp() // increment level by 1
{
    level++;
}

void Room::levelDown() // decrement level by 1
{
    level--;
}

int Room::getSize() // return size of treasure array
{
    return size;
}