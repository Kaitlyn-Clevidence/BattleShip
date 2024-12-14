#include "player.h"
#include "helpers.h"

PlayerBoard::PlayerBoard():Board(){
    boats = new Ship[5];
    numBoats = 0;
}
PlayerBoard::PlayerBoard(char* b, Ship* s, int n):Board(b){
    boats = new Ship[5];
    numBoats = n;
    for(int i = 0; i < numBoats; i++){
        boats[i] = s[i];
    }
}
PlayerBoard::PlayerBoard(const PlayerBoard& rhs):Board(rhs){
    boats = new Ship[5];
    numBoats = rhs.numBoats;
    for(int i = 0; i < numBoats; i++){
        boats[i] = rhs.boats[i];
    }
}

PlayerBoard::~PlayerBoard(){
    delete [] boats;
    boats = nullptr;
}
PlayerBoard PlayerBoard::operator=(const PlayerBoard& rhs){
    board = new char[100];
    for(int i = 0; i<100; i++){
        board[i] = rhs.board[i];
    }
    boats = new Ship[5];
    numBoats = rhs.numBoats;
    for(int i = 0; i < numBoats; i++){
        boats[i] = rhs.boats[i];
    }
    return *this;
}

Ship* PlayerBoard::getBoats() const{
    return boats;
}
int PlayerBoard::getNumBoats() const{
    return numBoats;
}
void PlayerBoard::setNumBoats(int i){
    numBoats = i;
}

char PlayerBoard::checkIfOpen(char c, int r){
    int position = posToIndex(c,r);
    switch(board[position]){
        case '.':
            return 'e'; //e for empty
        case 'S':
            return 's'; //s for ship
        case 'X': 
            return 'x'; //x for hit
        case 'O':
            return 'o'; //o for miss
        default:
            return 'w'; //w for whoops bc something is def wrong
    }
}
char PlayerBoard::checkIfOpen(int index){
    switch(board[index]){
        case '.':
            return 'e'; //e for empty
        case 'S':
            return 's'; //s for ship
        case 'X': 
            return 'x'; //x for hit
        case 'O':
            return 'o'; //o for miss
        default:
            return 'w'; //w for whoops bc something is def wrong
    }
}

bool PlayerBoard::checkWholeLocation(Ship b){
    int current = b.getFirstSquare();
    int first = (b.getFirstSquare()/10)%10;
    cout<<first<<endl;
    char check;
    if(b.getVertical()){
        for(int i = 0; i<b.getNumSquares(); i++){
            if(current>99){
                return false;
            }
            check = checkIfOpen(current);
            if(check!='e'){
                return false;
            }
            current+=10;
        }
    }
    else{
        for(int i = 0; i<b.getNumSquares(); i++){
            if(current>99){
                return false;
            }
            check = checkIfOpen(current);
            if(check!='e'){
                return false;
            }
            current++;
        }
    }
    return true;
}

bool PlayerBoard::checkIfAlive(Ship b){
    int first = b.getFirstSquare(), numHits = 0;
    char check;
    if(b.getVertical()){
        for(int i = 0; i<b.getNumSquares(); i++){
            check = checkIfOpen(first);
            if(check =='x'){
                numHits++;;
            }
            first+=10;
        }
    }
    else{
        for(int i = 0; i<b.getNumSquares(); i++){
            check = checkIfOpen(first);
            if(check =='x'){
                numHits++;
            }
            first++;
        }
    }
    if(numHits == b.getNumSquares()){
        numBoats--;
        //display message to screen about a ship being sunk
        return false;
    }
    else{
        return true;
    }
}

void operator<<(ostream out, PlayerBoard b){
    b.displayBoard();
}

void PlayerBoard::addNewBoat(Ship& b){
    boats[numBoats] = b;
    numBoats++;
}
void PlayerBoard::placeNewShip(const Ship& b){
    int current = b.getFirstSquare();
    if(current > 99 || current < 0){
        cout << "Index out of bounds"<<endl;
    }
    else if(b.getVertical()){
        for(int i = 0; i < b.getNumSquares(); i++){
            board[current] = 'S';
            current+=10;
        }
    }
    else{
        for(int i = 0; i < b.getNumSquares(); i++){
            board[current] = 'S';
            current++;
        }
    }
}

void operator+(PlayerBoard& p, Ship& b){
    p.addNewBoat(b);
    p.placeNewShip(b);
}

Ship PlayerBoard::whichShip(int index){
    int current;
    Ship merp;
    for(int i = 0; i<5;i++){
        current = boats[i].getFirstSquare();
        if(current > 99 || current < 0){
            cout << "Index out of bounds"<<endl;
        }
        else if(boats[i].getVertical()){
            for(int j = 0; j < boats[i].getNumSquares(); j++){
                if(current == index){
                    return boats[i];
                }
                current+=10;
            }
        }
        else{
            for(int j = 0; j < boats[i].getNumSquares(); j++){
                if(current == index){
                    return boats[i];
                }
                current++;
            }
        }
    }
    return merp;
}

bool PlayerBoard::checkIfWon(){
    int numHits = 0;
    for(int i = 0; i<100; i++){
        if(board[i] == 'X'){
            numHits++;
        }
    }
    if(numHits == 17){
        return true;
    }
    return false;
}