#include "ship.h"

Ship::Ship(){
    shipName = "default";
    numSquares = 0;
    firstSquare = 100;
    vertical = false;
}
Ship::Ship(string name, int num, int first, bool vert){
    shipName = name;
    numSquares = num;
    firstSquare = first;
    vertical = vert;
}
Ship::Ship(const Ship& rhs){
    shipName = rhs.shipName;
    numSquares = rhs.numSquares;
    firstSquare = rhs.firstSquare;
    vertical = rhs.vertical;
}

string Ship::getShipName() const{
    return shipName;
}
int Ship::getNumSquares() const{
    return numSquares;
}
int Ship::getFirstSquare() const{
    return firstSquare;
}
bool Ship::getVertical() const{
    return vertical;
}

void Ship::setShipName(const string name){
    shipName = name;
}
void Ship::setNumSquares(const int num){
    numSquares = num;
}
void Ship::setFirstSquare(const int first){
    firstSquare = first;
}
void Ship::setVertical(const bool orient){
    vertical = orient;
}
ostream &operator<<(ostream& out, Ship b){
    out<<b.shipName;
    return out;
}
