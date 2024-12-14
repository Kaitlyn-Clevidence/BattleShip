#include "board.h"

#ifndef PLAYER_H
#define PLAYER_H

class PlayerBoard:public Board{
    Ship* boats;
    int numBoats;

    void addNewBoat(Ship& b);
    void placeNewShip(const Ship& b);

    public:
        PlayerBoard();
        PlayerBoard(char* b, Ship* s, int n);
        PlayerBoard(const PlayerBoard& rhs);

        ~PlayerBoard();
        PlayerBoard operator=(const PlayerBoard& rhs);

        Ship* getBoats() const;
        int getNumBoats() const;
        void setNumBoats(int i);

        char checkIfOpen(char c, int r) override;
        char checkIfOpen(int index) override;

        bool checkWholeLocation(Ship b);

        friend void operator+(PlayerBoard& p, Ship& b);
        bool checkIfAlive(Ship b);

        friend void operator<<(ostream out, PlayerBoard b);
        Ship whichShip(int i);
        bool checkIfWon();
};

#endif