#include "ship.h"

#ifndef BOARD_H
#define BOARD_H

class Board{
    protected:
        char *board;

    public:
        Board();
        Board(char* b);
        Board(const Board& rhs);

        ~Board();
        Board& operator=(const Board& rhs);

        char* getBoard() const;
        void setBoard(char* b);
        
        virtual char checkIfOpen(char c, int r) = 0; //pure virtual makes this an abstract base class 
        virtual char checkIfOpen(int index) = 0;
        void displayBoard();

        friend void operator<<(char a, Board& b);

};
#endif