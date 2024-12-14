#include "board.h"
#include "helpers.h"

Board::Board(){
    board = new char[100];
    for(int i = 0; i<100; i++){
        board[i] = '.';
    }
}
Board::Board(char* b){
    board = new char[100];
    for(int i = 0; i<100; i++){
        board[i] = b[i];
    }
}
Board::Board(const Board& rhs){
    board = new char[100];
    for(int i = 0; i<100; i++){
        board[i] = rhs.board[i];
    }
}

Board::~Board(){
    delete [] board;
    board = nullptr;
}

Board& Board::operator=(const Board& rhs){
    board = new char[100];
    for(int i = 0; i<100; i++){
        board[i] = rhs.board[i];
    }
    return *this;
}

char* Board::getBoard() const{
    return board;
}
void Board::setBoard(char* b){
    board = b;
}

void Board::displayBoard(){
    int rows = 0, index = 0, column;
    cout<<"    A  B  C  D  E  F  G  H  I  J"<<endl;
    cout<<"---------------------------------"<<endl;
    for(rows; rows<10; rows++){
        if(rows+1 == 10){
            cout<<rows+1<<"|";
        }
        else{
            cout<<rows+1<<" |";
        }
        for(column = 0; column < 10; column++){
            cout<<" "<<board[index]<<" ";
            index++;
        }
        cout<<endl;
    }
}

void operator<<(char a, Board& b){
    b.displayBoard();
}
