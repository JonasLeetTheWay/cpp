#include <iostream>
#include <utility> 
#include <iomanip>

using namespace std;

class Robot {
/*
A robot simulator.

A robot factory's test facility needs a program to verify robot movements.

The robots have three possible movements :
turn right
turn left
advance

Robots are placed on a hypothetical infinite grid, 
facing a particular direction(north, east, south, or west)
at a set of { x, y } coordinates, e.g., { 3,8 },
with coordinates increasing to the northand east.

The robot then receives a number of instructions,
at which point the testing facility verifies the robot's new position, 
and in which direction it is pointing.

    The letter - string "RAALAL" means:
    Turn right
    Advance twice
    Turn left
    Advance once
    Turn left yet again

Say a robot starts at{ 7, 3 } facing north.Then running this stream of instructions should leave it at{ 9, 4 } facing west.
*/
public:
    pair<int,int> getCoordinate() {
        return this->coor;
    }
    void printCoordinate() {
        cout << "curr coordinate: "<< setw(2) <<"(" << this->coor.first <<","<< this->coor.second << ")" << endl;
    }
    void printDirection() {
        if (this->d == 1)
            cout << "curr head facing: " << setw(5) << "north" << endl;
        else if (this->d == 2)
            cout << "curr head facing: " << setw(5) << "south" << endl;
        else if (this->d == 3)
            cout << "curr head facing: " << setw(5) << "west" << endl;
        else if (this->d == 4)
            cout << "curr head facing: " << setw(5) << "east" << endl;
    }
  
    void status() {
        printCoordinate();
        printDirection();
        cout << endl;
    }


    void stringCommand(string str) {
        welcome();
        cout << "-------" << "Original" << "-------" << endl;
        status();
        for (int i = 0; i < str.length(); i++) {
            char command = str.at(i);
            if (command == 'A')
                advance();
            else if (command == 'L')
                turnLeft();
            else if (command == 'R')
                turnRight();
            status();
        }
        cout << "-------" << "Final" << "----------" << endl;
        status();
    }

    void turnLeft()  {
        switch (this->d) 
        {
        case 1: // currently facing north
            direction(3); break;
        case 2: // currently facing south
            direction(4); break;
        case 3: // currently facing west
            direction(2); break;
        case 4: // currently facing east
            direction(1); break;
        }
        cout << "-------" << "Left" << "-----------" << endl;
    }
    void turnRight() {
        switch (this->d)
        {
        case 1: // currently facing north
            direction(4); break;
        case 2: // currently facing south
            direction(3); break;
        case 3: // currently facing west
            direction(1); break;
        case 4: // currently facing east
            direction(2); break;
        }
        cout << "-------" << "Right" << "----------" << endl;
    }
    void setIncrement(int& val) {
        this->val = val;
        cout << ">> increment set" << endl;
    }
    void advance() {
        if (this->d == 1 || this->d == 2)
            y_coor_increment();
        if (this->d == 3 || this->d == 4)
            x_coor_increment();
        cout << "-------" << "Advanced" << "-------" << endl;
    }

private:
    // coordinate
    // default: starts at {7, 3} facing north
    int x=7, y=3; 
    // increment
    int val=1;
    // direction
    // default: facing north
    int d = 1; 
    pair<int,int> coor = { x, y };
    bool flag_x = false;
    bool flag_y = true;

    void direction(const int& d=1) 
    {
        switch (d) 
        {
        case 1: // up
            this->d = d;
            flag_y = true;
            break;
        case 2: // down
            this->d = d;
            flag_y = false;
            break;
        case 3: // left
            this->d = d;
            flag_x = false;
            break;
        case 4: // right
            this->d = d;
            flag_x = true;
            break;
        }
    }

    void x_coor_increment() 
    {
        if (flag_x) // right
        { 
            coor.first += val;
            !flag_x; // reset
        }
        else // left
        { 
            coor.first -= val;
            flag_x; // reset
        }
    }
    void y_coor_increment()
    {
        if (flag_y) // up
        {
            coor.second += val;
            !flag_y; // reset
        }
        else // down
        {
            coor.second -= val;
            flag_y; // reset
        }
    }

    void welcome()
    {
        cout << "Welcome to Robot Simulator created by Jonas ;)" << endl << endl << endl;
    }
    
};

int main(){

    // illustration
    Robot r;
    r.stringCommand("LLLLRRRRA");

    cin.get();
}