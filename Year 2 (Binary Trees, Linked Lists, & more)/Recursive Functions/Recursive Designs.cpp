#include<iostream>
#include <windows.h>

using namespace std;

COORD coord = {0,0};

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void function(int value, int x, int y, int direction)
{
    gotoxy(x,y);
    cout << "$";
    if(value > 1)
    {
        for(int i=0; i<value; i++)
        {
            if(direction == 0) //right
            {
                gotoxy(x+i+1, y);
            }
            else if(direction == 1) //left
            {
                gotoxy(x-i-1, y);
            }
            else if(direction == 2) //up
            {
                gotoxy(x, y-1-i);
            }
            else //down
            {
                gotoxy(x, y+1+i);
            }
            cout << "-";
        }
        int newValueX, newValueY;
        if(direction == 0)
        {
            newValueX = x + value + 1;
            newValueY = y;
            direction = 2;
            function(value/2, newValueX, newValueY, direction);
            function(value/2, newValueX, newValueY, direction-2);
            function(value/2, newValueX, newValueY, direction+1);
        }
        else if(direction == 1)
        {
            newValueX = x - value -1;
            newValueY = y;
            direction = 3;
            function(value/2, newValueX, newValueY, direction);
            function(value/2, newValueX, newValueY, direction-2);
            function(value/2, newValueX, newValueY, direction-1);
        }
        else if(direction == 2)
        {
            newValueX = x;
            newValueY = y-1-value;
            direction = 1;
            function(value/2, newValueX, newValueY, direction);
            function(value/2, newValueX, newValueY, direction+1);
            function(value/2, newValueX, newValueY, direction-1);
        }
        else
        {
            newValueX = x;
            newValueY = y + 1 + value;
            direction = 0;
            function(value/2, newValueX, newValueY, direction);
            function(value/2, newValueX, newValueY, direction+3);
            function(value/2, newValueX, newValueY, direction+1);
        }
    }
    else
    {
        if(direction == 0)
        {
            gotoxy(x+1, y);
            cout << "-$";
        }
        else if(direction == 1)
        {
            gotoxy(x-2, y);
            cout << "$-";
        }
        else if(direction ==2)
        {
            gotoxy(x, y-1);
            cout << "-";
            gotoxy(x, y-2);
            cout << "$";
        }
        else
        {
            gotoxy(x, y+1);
            cout << "-";
            gotoxy(x, y+2);
            cout << "$";
        }
    }
}

int main()
{
    int value, x, y, direction;
    cout << "Input starting (x,y) coordinates." << endl;
    cin >> x >> y;
    cout << "Input integer value with power of 2." << endl;
    cin >> value;
    cout << "Input Direction: 0 for right, 1 for left, 2 for up, 3 for down" << endl;
    cin >> direction;
    function(value,x,y,direction);
    for (int i = 0; i <  25 ; i++)
    {
        cout << endl;
    }
    return 0;
}
