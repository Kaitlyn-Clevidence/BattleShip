#include "ship.h"
#include "opponent.h"
#include "player.h"

#ifndef HELPERS_H
#define HELPERS_H

int posToIndex(char c, int r);
void displayIntro();
void userTurn(PlayerBoard userPlay, OpponentBoard& userOpp, PlayerBoard& compPlay, int& turn);
void ComputerTurn(OpponentBoard& compOpp, PlayerBoard& userPlay, int& turn);
void userBoardSetup(PlayerBoard& user);
void computerBoardSetup(PlayerBoard& computer);
void updatePlayerBoard(PlayerBoard& current, int i);
void updateOpponentBoard(PlayerBoard& opponent, OpponentBoard& current);
bool checkIfWon(PlayerBoard p);

#endif