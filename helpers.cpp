#include "helpers.h"

int posToIndex(char c, int r){
    string index, row;
    int i;
    switch(c){
        case 'A':
            index = "0";
            break;
        case 'B':
            index = "1";
            break;
        case 'C':
            index = "2";
            break;
        case 'D':
            index = "3";
            break;
        case 'E':
            index = "4";
            break;
        case 'F':
            index = "5";
            break;
        case 'G':
            index = "6";
            break;
        case 'H':
            index = "7";
            break;
        case 'I':
            index = "8";
            break;
        case 'J':
            index = "9";
            break;
        case 'a':
            index = "0";
            break;
        case 'b':
            index = "1";
            break;
        case 'c':
            index = "2";
            break;
        case 'd':
            index = "3";
            break;
        case 'e':
            index = "4";
            break;
        case 'f':
            index = "5";
            break;
        case 'g':
            index = "6";
            break;
        case 'h':
            index = "7";
            break;
        case 'i':
            index = "8";
            break;
        case 'j':
            index = "9";
            break;
        default:
            cout<<"Invalid index"<<endl;
            return 100;
    }
    row = to_string(r-1);
    row = row+index;
    i = stoi(row);
    return i;
}
void displayIntro(){
    system("clear");
    cout<<"Welcome to Battleship!"<<endl;
    cout<<"In this game, you will place five ships on the board"<<endl;
    cout<<"Then, there will be alternating turns between you and the computer."<<endl;
    cout<<"During these turns, you will attempt to hit and ultimately sink your opponent's ships."<<endl;
    cout<<"The first to sink all of their opponent's ships wins the game."<<endl;
    cout<<"Are you ready to play? (y/n): ";
}
void userTurn(PlayerBoard userPlay, OpponentBoard& userOpp, PlayerBoard& compPlay, int& turn){
    char out = 'c', c, validation;
    int r, index;
    Ship hit;
    bool alive;
    cout<<"Your Ships:"<<endl;
    out<<userPlay;
    cout<<endl;
    //check positioning online
    cout<<"Attack Map:"<<endl;
    out<<userOpp;

    do{
        cout<<"Where would you like to attack? ";
        cin>>c>>r;
        index = posToIndex(c, r);
        validation = compPlay.checkIfOpen(index);
        if(validation == 'e'|| validation == 's'){
            updatePlayerBoard(compPlay, index);
            updateOpponentBoard(compPlay, userOpp);
            if(validation == 's'){
                //check if hit and alive at this index
                hit = compPlay.whichShip(index);
                compPlay.setNumBoats(5);
                alive = compPlay.checkIfAlive(hit);
                cout<<"Attack Map:"<<endl;
                out<<userOpp;
                if(!alive){
                    cout<<"You sunk your opponent's "<<hit<<"!"<<endl;
                }
                else{
                    cout<<"You hit your opponent's "<<hit<<"!"<<endl;
                }
            }
        }
    }while(validation!= 'e'); //to e and not e or s because if it is a hit, repeat turn until a miss 
    turn++;
}
void ComputerTurn(OpponentBoard& compOpp, PlayerBoard& userPlay, int& turn){
    char c, validation;
    int r, index;
    Ship hit;
    bool alive;
    if(!userPlay.checkIfWon()){
        do{
            srand((unsigned)time(0));
            index = (rand() % 100);
            validation = userPlay.checkIfOpen(index);
            if(validation == 'e'|| validation == 's'){
                updatePlayerBoard(userPlay, index);
                updateOpponentBoard(userPlay, compOpp);
                if(validation =='s'){
                    //check if hit and alive at this index
                    hit = userPlay.whichShip(index);
                    userPlay.setNumBoats(5);
                    alive = userPlay.checkIfAlive(hit);
                    if(!alive){
                        cout<<"Your opponent sunk your "<<hit.getShipName()<<"!"<<endl;
                    }
                    else{
                        cout<<"Your opponent hit your "<<hit.getShipName()<<"!"<<endl;
                    }
                }
            }
        }while(validation!= 'e');
        turn++;
    }
}
void userBoardSetup(PlayerBoard& user){
    char c,v, out = 'c';
    int r, i;
    bool vert = false, check;
    string currentName;
    //Carrier
    system("clear");
    out << user;
    do{
        check = false;
        currentName = "Carrier";
        cout<<"Where would you like the first space of the Carrier (Column Row ex: D 4): ";
        cin>>c>>r;
        cout<<"Would you like the Carrier to be vertical or horizontal? (v/h): ";
        cin>>v;
        if(v == 'v'||v=='V'){
            vert = true;
        }
        else{
            vert = false;
        }
        i = posToIndex(c,r);
        Ship Carrier = Ship(currentName, 5, i, vert);
        check = user.checkWholeLocation(Carrier);
        if(check){
            user+Carrier;
        }
        else{
            cout<<"Please pick a valid location."<<endl;
        }
    }while(check == false);
    //Battleship
    system("clear");
    out << user;
    do{
        check = false;
        currentName = "Battleship";
        cout<<"Where would you like the first space of the Battleship (Column Row ex: D 4): ";
        cin>>c>>r;
        cout<<"Would you like the Battleship to be vertical or horizontal? (v/h): ";
        cin>>v;
        if(v == 'v'|| v=='V'){
            vert = true;
        }
        else{
            vert = false;
        }
        i = posToIndex(c,r);
        Ship Battleship = Ship(currentName, 4, i, vert);
        check = user.checkWholeLocation(Battleship);
        if(check){
            user+Battleship;
        }
        else{
            cout<<"Please pick a valid location."<<endl;
        }
    }while(check == false);
    //Submarine
    system("clear");
    out << user;
    do{
        check = false;
        currentName = "Submarine";
        cout<<"Where would you like the first space of the Submarine (Column Row ex: D 4): ";
        cin>>c>>r;
        cout<<"Would you like the Submarine to be vertical or horizontal? (v/h): ";
        cin>>v;
        if(v == 'v'||v=='V'){
            vert = true;
        }
        else{
            vert = false;
        }
        i = posToIndex(c,r);
        Ship Submarine = Ship(currentName, 3, i, vert);
        check = user.checkWholeLocation(Submarine);
        if(check){
            user+Submarine;
        }
        else{
            cout<<"Please pick a valid location."<<endl;
        }
    }while(check == false);
    //Destroyer
    system("clear");
    out << user;
    do{
        check = false;
        currentName = "Destroyer";
        cout<<"Where would you like the first space of the Destroyer (Column Row ex: D 4): ";
        cin>>c>>r;
        cout<<"Would you like the Destroyer to be vertical or horizontal? (v/h): ";
        cin>>v;
        if(v == 'v'||v=='V'){
            vert = true;
        }
        else{
            vert = false;
        }
        i = posToIndex(c,r);
        Ship Destroyer = Ship(currentName, 3, i, vert);
        check = user.checkWholeLocation(Destroyer);
        if(check){
            user+Destroyer;
        }
        else{
            cout<<"Please pick a valid location."<<endl;
        }
    }while(check == false);
    //Patrol Boat
    system("clear");
    out << user;
    do{
        check = false;
        currentName = "Patrol Boat";
        cout<<"Where would you like the first space of the Patrol Boat (Column Row ex: D 4): ";
        cin>>c>>r;
        cout<<"Would you like the Patrol Boat to be vertical or horizontal? (v/h): ";
        cin>>v;
        if(v == 'v'||v=='V'){
            vert = true;
        }
        else{
            vert = false;
        }
        i = posToIndex(c,r);
        Ship PatrolBoat = Ship(currentName, 2, i, vert);
        check = user.checkWholeLocation(PatrolBoat);
        if(check){
            user+PatrolBoat;
        }
        else{
            cout<<"Please pick a valid location."<<endl;
        }
    }while(check == false);
}
void computerBoardSetup(PlayerBoard& computer){
    char c;
    int  i, v;
    bool vert = false, check;
    string currentName;

    srand((unsigned)time(0));
    //Carrier
    do{
        check = false;
        currentName = "Carrier";
        //get random index from 0-99 and set i to it
        i = (rand() % 100);
        //get random value from 1 to 10. if %2 = 0, v == false and if not v == true
        v = (rand() % 10);
        if(v % 2 == 0){
            vert = true;
        }
        else{
            vert = false;
        }
        Ship Carrier = Ship(currentName, 5, i, vert);
        check = computer.checkWholeLocation(Carrier);
        if(check){
            computer+Carrier;
        }
    }while(check == false);
    //Battleship
    do{
        check = false;
        currentName = "Battleship";
        //get random index from 0-99 and set i to it
        i = (rand() % 100);
        //get random value from 1 to 10. if %2 = 0, v == false and if not v == true
        v = (rand() % 10);
        if(v % 2 == 0){
            vert = true;
        }
        else{
            vert = false;
        }
        Ship Battleship = Ship(currentName, 4, i, vert);
        check = computer.checkWholeLocation(Battleship);
        if(check){
            computer+Battleship;
        }
    }while(check == false);
    //Submarine
    do{
        check = false;
        currentName = "Submarine";
        //get random index from 0-99 and set i to it
        i = (rand() % 100);
        //get random value from 1 to 10. if %2 = 0, v == false and if not v == true
        v = (rand() % 10);
        if(v % 2 == 0){
            vert = true;
        }
        else{
            vert = false;
        }
        Ship Submarine = Ship(currentName, 3, i, vert);
        check = computer.checkWholeLocation(Submarine);
        if(check){
            computer+Submarine;
        }
    }while(check == false);
    //Destroyer
    do{
        check = false;
        currentName = "Destroyer";
        //get random index from 0-99 and set i to it
        i = (rand() % 100);
        //get random value from 1 to 10. if %2 = 0, v == false and if not v == true
        v = (rand() % 10);
        if(v % 2 == 0){
            vert = true;
        }
        else{
            vert = false;
        }
        Ship Destroyer = Ship(currentName, 3, i, vert);
        check = computer.checkWholeLocation(Destroyer);
        if(check){
            computer+Destroyer;
        }
    }while(check == false);
    //Patrol Boat
    do{
        system("clear");
        check = false;
        currentName = "Patrol Boat";
        //get random index from 0-99 and set i to it
        i = (rand() % 100);
        //get random value from 1 to 10. if %2 = 0, v == false and if not v == true
        v = (rand() % 10);
        if(v % 2 == 0){
            vert = true;
        }
        else{
            vert = false;
        }
        Ship PatrolBoat = Ship(currentName, 2, i, vert);
        check = computer.checkWholeLocation(PatrolBoat);
        if(check){
            computer+PatrolBoat;
        }
    }while(check == false);
}
void updatePlayerBoard(PlayerBoard& current, int i){
    if(current.getBoard()[i] == '.'){
        current.getBoard()[i] = 'O';
    }
    else if(current.getBoard()[i] == 'S'){
        current.getBoard()[i] = 'X';
    }
}
void updateOpponentBoard(PlayerBoard& opponent, OpponentBoard& current){
    for(int i = 0; i<100; i++){
        if(opponent.getBoard()[i] == 'X'){
            current.getBoard()[i] = 'X';
        }
        else if(opponent.getBoard()[i] == 'O'){
            current.getBoard()[i] = 'O';
        }
    }
}

//weird logic but i think it will work :)
/*bool checkIfWon(PlayerBoard p){
    p.setNumBoats(5);
    for(int i = 0; i < 5; i++){
        p.checkIfAlive(p.getBoats()[i]);
    }

    if(p.getNumBoats() == 0){
        return true;
    }

    return false;
}*/