#include "opponent.h"
#include "helpers.h"

OpponentBoard::OpponentBoard():Board(){
    //Board takes care of it
}
OpponentBoard::OpponentBoard(char* b):Board(b){
    //Board takes care of it
}
OpponentBoard::OpponentBoard(const OpponentBoard& rhs):Board(rhs){
    //Board takes care of it
}

OpponentBoard::~OpponentBoard(){
    //Board takes care of it
}
OpponentBoard OpponentBoard::operator=(const OpponentBoard& rhs){
    board = new char[100];
    for(int i = 0; i<100; i++){
        board[i] = rhs.board[i];
    }
    return *this;
}

char OpponentBoard::checkIfOpen(char c, int r){
    int position = posToIndex(c,r);
    switch(board[position]){
        case '.':
            return 'e'; //e for empty
        case 'X': 
            return 'x'; //x for hit
        case 'O':
            return 'o'; //o for miss
        default:
            return 'w'; //w for whoops bc something is def wrong
    }
}
char OpponentBoard::checkIfOpen(int index){
    switch(board[index]){
        case '.':
            return 'e'; //e for empty
        case 'X': 
            return 'x'; //x for hit
        case 'O':
            return 'o'; //o for miss
        default:
            return 'w'; //w for whoops bc something is def wrong
    }
}

/*void operator<<(ostream out, OpponentBoard b){
    b.displayBoard();
}*/