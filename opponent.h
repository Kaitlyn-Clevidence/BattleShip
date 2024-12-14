#include "board.h"

#ifndef OPPONENT_H
#define OPPONENT_H

class OpponentBoard:public Board{

    public:
        OpponentBoard();
        OpponentBoard(char* b);
        OpponentBoard(const OpponentBoard& rhs);

        ~OpponentBoard();
        OpponentBoard operator=(const OpponentBoard& rhs);

        char checkIfOpen(char c, int r) override;
        char checkIfOpen(int index) override;

        /*friend void operator<<(ostream out, OpponentBoard b);*/
};

#endif