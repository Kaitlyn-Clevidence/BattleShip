#include "helpers.h"

int main(){
    PlayerBoard userPlayer, computerPlayer;
    OpponentBoard userOpponent, computerOpponent;
    char playGame;
    int turn;
    bool win = false;
    displayIntro();

    do{
        cin>>playGame;
    }while(playGame != 'y' && playGame != 'Y' && playGame != 'n' && playGame!='N');
    if(playGame == 'n' || playGame == 'N'){
        cout<<"Goodbye!"<<endl;
        return 0;
    }

    while(playGame == 'y' || playGame == 'Y'){
        //seed randomizer
        srand((unsigned)time(0));
        //randomize turn to be 1 or 2 
        turn = (rand() % 10);
        //setup computer board
        computerBoardSetup(computerPlayer);
        //setup user board
        userBoardSetup(userPlayer);
        system("clear");
        do{
            if(turn % 2 == 0){
                userTurn(userPlayer, userOpponent, computerPlayer, turn);
                win = computerPlayer.checkIfWon();
                if(win){
                    cout<<"You won!! Would you like to play again? ";
                }
            }
            else{
                ComputerTurn(computerOpponent, userPlayer, turn);
                win = userPlayer.checkIfWon();
                if(win){
                    cout<<"You lost!! Would you like to play again? ";
                }
            }
        }while(!win);
        cin>>playGame;
    }
}