#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<windows.h>

using namespace std;

COORD coord = {0,0};

void gotoxy(int x, int y)
{
    coord.X = 6*x+3;
    coord.Y = 3*y+2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Piece
{
    private:
        int xpos;
        int ypos;
        int distanceTravelled;
        char color;
        string piecenumber;
        int originalx;
        int originaly;
        int goalx;
        int goaly;
    public:
//        Piece(x,y,c,p); //don't forget to add d here
        Piece(int, int, char, string);
        int getx();
        int gety();
        char getc();
        string getpname();
        int getd();
        void setx(int);
        void sety(int);
        void setd(int);
        void piecedisplay();
};

Piece::Piece(int x, int y, char c, string p)
{
    xpos = x;
    ypos = y;
    color = c;
    piecenumber = c+p;
    originalx = x;
    originaly = y;
    goalx = 5;
    goaly = 5;
}

int Piece::getx()
{
    return xpos;
}

int Piece::gety()
{
    return ypos;
}

char Piece::getc()
{
    return color;
}

string Piece::getpname()
{
    return piecenumber;
}

int Piece::getd()
{
    return distanceTravelled;
}

void Piece::setx(int x)
{
    xpos = x;
}

void Piece::sety(int y)
{
    ypos = y;
}

void Piece::setd(int distance)
{
    distanceTravelled = distance;
}

void Piece::piecedisplay()
{
    gotoxy(xpos, ypos);
    cout << getpname() << endl;
}

class Board
{
    private:
        Piece players[8];
//      void loadChanceCards();
//      int numberAtGoal[4] = {0, 0, 0, 0}
    public:
        Board();
        int roll();
        void moveNormal(int);
//        void moveGoal();
//        void chance();
//        bool atLocation();
    void execute();
    void display();

    //first number:5, second number:13
    string boardContent [11][11] =
    {   {"","1","2","3","4","5","6","7","8","9",""},
        {"1","X","X","R2","R1","X","X","X","X","X","1"},
        {"2","X","","","","","","Y1","","X","2"},
        {"3","X","","X","X","","X","X","","Y2","3"},
        {"4","X","","X","X","","X","X","","","4"},
        {"5","X","","","","G","","","","X","5"},
        {"6","","","X","X","","X","X","","X","6"},
        {"7","B2","B1","X","X","","X","X","","X","7"},
        {"8","X","","","","","","","G1","X","8"},
        {"9","X","X","X","X","X","","G2","X","X","9"},
        {"","1","2","3","4","5","6","7","8","9",""},
    };
}; //change where B1 should go if you want to go to (3,8) look for point 8,3

Board::Board()
    : players {{7,2,'B',"1"}, {1,7,'B',"2"}, {8,8,'G',"1"}, {7,9,'G',"2"}, {2,7,'Y',"1"}, {9,3,'Y',"2"},
                {4,1,'R',"1"}, {3,1,'R',"2"}}
{


}

void Board::moveNormal(int currentPlayer)
{
    int current_x = players[currentPlayer].getx();
    int current_y = players[currentPlayer].gety();
    int distance = players[currentPlayer].getd();
    int new_x, new_y;
    if(current_y == 2)
    {
        if((current_x + distance) <= 8)
        {
            new_x  = current_x + distance ;
            new_y =  current_y ;  // does not change
        }
        else
        {
            new_x  = 8;
            new_y = current_y + (distance - (8 - current_x));
        }
    }
    else if(current_x == 8)
    {
        if((current_y + distance <= 8))
        {
           new_x = current_x; // still stays at col 8
           new_y = current_y + distance;
        }
        else
        {
           new_x = current_x - (distance - (8 - current_y));
           new_y = 8;
        }
    }
    else if(current_y == 8)
    {
        if((distance <= current_x - 2))
        {
            new_x = current_x - distance;
            new_y = current_y;
        }
        else
        {
            new_x = 2;
            new_y = (8 - distance) + (current_x - 2);
        }
    }
    else if(current_x == 2)
    {
        if((distance <= current_y - 2))
        {
            new_x = current_x;
            new_y = current_y - distance;
        }
        else
        {
            new_x = current_x + (distance - (current_y - 2));
            new_y = 2;
        }
    }

    players[currentPlayer].setx(new_x);
    players[currentPlayer].sety(new_y);

    boardContent[current_x][current_y] = "";
    boardContent[new_x][new_y] = players[currentPlayer].getpname();
}

int Board::roll()
{
    int dice = (rand()%3)+1;
    return dice;
}

void Board::display()
{
    cout << " _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ " << endl;
    for (int i=0; i<11; i++)
    {
        cout << "|     |     |     |     |     |     |     |     |     |     |     |" << endl;
        cout << "|     |     |     |     |     |     |     |     |     |     |     |" << endl;
        cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
    }

    for(int i = 0 ; i < 11; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            //going through each element
            gotoxy(i, j);
            cout << boardContent[i][j];
        }
    }
    // Adding space to move process returned below
    cout << endl;
    cout << endl;
}

void Board::execute()
{
    char pause;
    int dice1, dice2;
    srand(time(NULL));
    int numberOfPlayers;
    int currentPlayer = 0; // set first blue player as starter
    int pieceNumber;
    string input;
    display();
    gotoxy(-1,10);
    cout << "How many players?" << endl;
    cin >> numberOfPlayers;
    cout << "To start, enter 'p'." << endl;
    cin >> pause;

    while(pause == 'p')
    {
        system("CLS");
        dice1 = roll();
        dice2 = roll();
        int sum = dice1 + dice2;
        if(currentPlayer == 0)
        {
            cout << "Piece 1 or 2? ";
            cin >> pieceNumber;
            if(pieceNumber == 1)
            {
                if(players[0].getx() == 1 && players[0].gety() == 6)
                {
                    if(dice1 == dice2)
                    {
                        players[0].setx(6);
                        players[0].sety(2);
                        boardContent[6][1] = "";
                        boardContent[6][2] = "B1";
                        display();
                    }
                    else
                    {
                        display();
                    }
                }
                else
                {
                    players[currentPlayer].setd(sum);
                    moveNormal(currentPlayer);
                    display();
                }
                cout << endl;
                cout << "Player Color: B1" << endl; //change to getpname()
                cout << "Dice Roll: " << dice1 << " " << dice2 << endl;
                cout << "Press p to continue" << endl;
                cin >> pause;
                system("CLS");
                if(currentPlayer+1 < numberOfPlayers)
                {
                    currentPlayer++;
                }
                else
                {
                    currentPlayer = 0;
                }
            }
            else if(pieceNumber == 2)
            {
                if(players[1].getx() == 1 && players[1].gety() == 7)
                {
                    if(dice1 == dice2)
                    {
                        players[1].setx(6);
                        players[1].sety(2);
                        boardContent[7][1] = "";
                        boardContent[6][2] = "B2";
                        display();
                    }
                    else
                    {
                        display();
                    }
                }
                else
                {
                    players[currentPlayer+1].setd(sum);
                    moveNormal(currentPlayer+1);
                    display();
                }
                cout << endl;
                cout << "Player Color: B2" << endl; //change to getpname()
                cout << "Dice Roll: " << dice1 << " " << dice2 << endl;
                cout << "Press p to continue" << endl;
                cin >> pause;
                system("CLS");
                if(currentPlayer+1 < numberOfPlayers)
                {
                    currentPlayer++;
                }
                else
                {
                    currentPlayer = 0;
                }
            }
        }
        if(currentPlayer == 1)
        {
            cout << "Piece 1 or 2? ";
            cin >> pieceNumber;
            if(pieceNumber == 1)
            {
                if(players[2].getx() == 6 && players[2].gety() == 9)
                {
                    if(dice1 == dice2)
                    {
                        players[2].setx(8);
                        players[2].sety(6);
                        boardContent[9][6] = "";
                        boardContent[8][6] = "G1";
                        display();
                    }
                    else
                    {
                        display();
                    }
                }
                else
                {
                    players[currentPlayer+1].setd(sum);
                    moveNormal(currentPlayer+1);
                    display();
                }
                cout << endl;
                cout << "Player Color: G1" << endl; //change to getpname()
                cout << "Dice Roll: " << dice1 << " " << dice2 << endl;
                cout << "Press p to continue" << endl;
                cin >> pause;
                system("CLS");
                if(currentPlayer+1 < numberOfPlayers)
                {
                    currentPlayer++;
                }
                else
                {
                    currentPlayer = 0;
                }
            }
            else if(pieceNumber == 2)
            {
                if(players[3].getx() == 7 && players[3].gety() == 9)
                {
                    if(dice1 == dice2)
                    {
                        players[3].setx(8);
                        players[3].sety(6);
                        boardContent[9][7] = "";
                        boardContent[8][6] = "G2";
                        display();
                    }
                    else
                    {
                        display();
                    }
                }
                else
                {
                    players[currentPlayer+2].setd(sum);
                    moveNormal(currentPlayer+2);
                    display();
                }
                cout << endl;
                cout << "Player Color: G2" << endl; //change to getpname()
                cout << "Dice Roll: " << dice1 << " " << dice2 << endl;
                cout << "Press p to continue" << endl;
                cin >> pause;
                system("CLS");
                if(currentPlayer+1 < numberOfPlayers)
                {
                    currentPlayer++;
                }
                else
                {
                    currentPlayer = 0;
                }
            }
        }
        if(currentPlayer == 2)
        {
            cout << "Piece 1 or 2? ";
            cin >> pieceNumber;
            if(pieceNumber == 1)
            {
                if(players[4].getx() == 9 && players[4].gety() == 4)
                {
                    if(dice1 == dice2)
                    {
                        players[4].setx(4);
                        players[4].sety(8);
                        boardContent[4][9] = "";
                        boardContent[4][8] = "Y1";
                        display();
                    }
                    else
                    {
                        display();
                    }
                }
                else
                {
                    players[currentPlayer+2].setd(sum);
                    moveNormal(currentPlayer+2);
                    display();
                }
                cout << endl;
                cout << "Player Color: Y1" << endl; //change to getpname()
                cout << "Dice Roll: " << dice1 << " " << dice2 << endl;
                cout << "Press p to continue" << endl;
                cin >> pause;
                system("CLS");
                if(currentPlayer+1 < numberOfPlayers)
                {
                    currentPlayer++;
                }
                else
                {
                    currentPlayer = 0;
                }
            }
            else if(pieceNumber == 2)
            {
                if(players[5].getx() == 9 && players[5].gety() == 3)
                {
                    if(dice1 == dice2)
                    {
                        players[5].setx(4);
                        players[5].sety(8);
                        boardContent[3][9] = "";
                        boardContent[4][8] = "Y2";
                        display();
                    }
                    else
                    {
                        display();
                    }
                }
                else
                {
                    players[currentPlayer+3].setd(sum);
                    moveNormal(currentPlayer+3);
                    display();
                }
                cout << endl;
                cout << "Player Color: Y2" << endl; //change to getpname()
                cout << "Dice Roll: " << dice1 << " " << dice2 << endl;
                cout << "Press p to continue" << endl;
                cin >> pause;
                system("CLS");
                if(currentPlayer+1 < numberOfPlayers)
                {
                    currentPlayer++;
                }
                else
                {
                    currentPlayer = 0;
                }
            }
        }
        if(currentPlayer == 3)
        {
            cout << "Piece 1 or 2? ";
            cin >> pieceNumber;
            if(pieceNumber == 1)
            {
                if(players[6].getx() == 4 && players[6].gety() == 1)
                {
                    if(dice1 == dice2)
                    {
                       players[6].setx(2);
                        players[6].sety(4);
                        boardContent[1][4] = "";
                        boardContent[2][4] = "R1";
                        display();
                    }
                    else
                    {
                        display();
                    }
                }
                else
                {
                    players[currentPlayer+3].setd(sum);
                    moveNormal(currentPlayer+3);
                    display();
                }
                cout << endl;
                cout << "Player Color: R1" << endl; //change to getpname()
                cout << "Dice Roll: " << dice1 << " " << dice2 << endl;
                cout << "Press p to continue" << endl;
                cin >> pause;
                system("CLS");
                if(currentPlayer+1 < numberOfPlayers)
                {
                    currentPlayer++;
                }
                else
                {
                    currentPlayer = 0;
                }
            }
            else if(pieceNumber == 2)
            {
                if(players[7].getx() == 3 && players[7].gety() == 1)
                {
                    if(dice1 == dice2)
                    {
                        players[7].setx(2);
                        players[7].sety(4);
                        boardContent[1][3] = "";
                        boardContent[2][4] = "R2";
                        display();
                    }
                    else
                    {
                        display();
                    }
                }
                else
                {
                    players[currentPlayer+4].setd(sum);
                    moveNormal(currentPlayer+4);
                    display();
                }
                cout << endl;
                cout << "Player Color: R2" << endl; //change to getpname()
                cout << "Dice Roll: " << dice1 << " " << dice2 << endl;
                cout << "Press p to continue" << endl;
                cin >> pause;
                system("CLS");
                if(currentPlayer+1 < numberOfPlayers)
                {
                    currentPlayer++;
                }
                else
                {
                    currentPlayer = 0;
                }
            }
        }
    }
}

int main()
{
    Board b;
    b.execute();
    return 0;
}
