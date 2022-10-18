// CS1300 Spring 2021
// Aurora: Punith Sandhu
// Recitation: 219 - Michael Hoefer
// Project 3 - Room class

#ifndef ROOM_H
#define ROOM_H

#include <string>
using namespace std;
class Room
{
    public:
        Room(); // set room name to Red room , and treasure to stuff in red room
        string getRoomName(); // return room name
        void setRoomName(); // set name of room to given string
        string getTreasureName(int ind); //return names of treasures in the room
        void setTreasureNames(); // set names of treasure into array of strings
        int getLevel(); // return level number
        void levelUp(); // increment level by 1
        void levelDown(); // decrement level by 1
        int getSize(); // return size of treasure array
        
    private:
        int level;
        string roomName; // room name
        string treasure[3]; // array of treasures(3 treasure in each room)
        const static int size = 3; // The capacity of the treasure array (3). Constant

};

#endif