#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#ifndef SHIP_H
#define SHIP_H

class Ship{
    string shipName;
    int numSquares, firstSquare;
    bool vertical;

    public: 
        Ship();
        Ship(string name, int num, int first, bool vert);
        Ship(const Ship& rhs);

        string getShipName() const;
        int getNumSquares() const;
        int getFirstSquare() const;
        bool getVertical() const;

        void setShipName(const string name);
        void setNumSquares(const int num);
        void setFirstSquare(const int first);
        void setVertical(const bool orient);

        friend ostream &operator<<(ostream& out, Ship b);
}; 

#endif