#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

ifstream myfile("D://Contest3.txt");

// Check if piece is blocked or will go out of edge
int checkValidLeftToRight(vector <int> blocked, int pieceNumber, int startPos, int row, int column)
{
    int returnVal = 0;
    //Find the row and column index
    int remainder = startPos%column;
    int currentRow, currentCol;
    currentRow = startPos/column;
    if(remainder == 0) // last column
    {
        currentRow = currentRow -1;
        currentCol = column-1;
    }
    else
    {
        currentCol = remainder -1 ;
    }

    for(int i=0; i<blocked.size(); i++)
    {
        if(pieceNumber == 1)
        {
            if(currentCol +2 > column-1) return 1; // Check if it moves out of the edge
            // Check for blocked
            if(startPos == blocked[i] || (startPos+1) == blocked[i] || (startPos+2) == blocked[i])
            {
                return 1;
            }
        }
        else if(pieceNumber == 2)
        {
            if ((currentCol+1 > column-1) || (currentRow +1 > row-1)) return 1; // Check edge case
            // Check if blocked
            if(startPos == blocked[i] || (startPos+column) == blocked[i] || (startPos+column+1) == blocked[i])
            {
                return 1;
            }
        }
        else if(pieceNumber == 3)
        {
            if((currentCol+1 > column-1) || (currentRow+2 > row-1 )) return 1; // Check edge case
            // Check if blocked
            if(startPos == blocked[i] || (startPos+1) == blocked[i] || (startPos+column+1) == blocked[i] || (startPos+2*column+1) == blocked[i])
            {
                return 1;
            }
        }
    }
    return returnVal; // Should return 0
}

void lefttoright(vector <int> blocked, int startPos, int row, int column)
{
    int start = startPos;
    int endPos = start;
    int counter = 1;
    while(endPos%column != 0)
    {
        if(checkValidLeftToRight(blocked, counter, start, row, column) == 0) //not blocked
        {
            if(counter == 1)
            {
                start = start+3;
                cout << "A";
            }
            else if(counter == 2)
            {
                start = start+column+2;
                cout << "B";
            }
            else if(counter == 3)
            {
                start = start+1+2*column+1;
                cout << "C";
            }
            endPos = start-1;
        }
        counter++;
        if(counter == 4) counter = 1; // reset after third piece
    }
    cout << endl;
}

// Check if piece is blocked or will go out of edge
int checkValidRightToLeft(vector <int> blocked, int pieceNumber, int startPos, int row, int column)
{
    //Find the row and column index
    int remainder = startPos%column;
    int currentRow, currentCol;
    currentRow = startPos/column;
    if(remainder == 0)
    {
        currentRow = currentRow-1;
        currentCol = column-1;
    }
    else
    {
        currentCol = remainder-1;
    }

    for(int i=0; i<blocked.size(); i++)
    {
        if(pieceNumber == 1)
        {
            if(currentCol -2 < 0) return 1; // Check if it moves out of the edge
            // Check for blocked
            if(startPos == blocked[i] || (startPos -1) == blocked[i] || (startPos-2) == blocked[i])
            {
                return 1;
            }
        }
        else if(pieceNumber == 2)
        {
            if ((currentCol-1 < 0) || (currentRow - 1  < 0)) return 1; // Check edge case
            // Check if blocked
            if(startPos == blocked[i] || (startPos-1) == blocked[i] || (startPos-column-1) == blocked[i])
            {
                return 1;
            }
        }
        else if(pieceNumber == 3)
        {
            if((currentCol-1 < 0) || (currentRow-2 < 0 )) return 1; // Check edge case
            // Check if blocked
            if(startPos == blocked[i] || (startPos-column) == blocked[i] || (startPos-2*column) == blocked[i] || (startPos-2*column-1) == blocked[i])
            {
                return 1;
            }
        }
    }
    return 0;
}

void righttoleft(vector <int> blocked, int startPos, int row, int column)
{
    int start = startPos;
    int endPos = start;
    int counter = 1;
    string outputString = "";
    while(endPos != 0)
    {
        if(checkValidRightToLeft(blocked, counter, start, row, column) == 0) //not blocked
        {
            if(counter == 1)
            {
                start = start-3;
                outputString = outputString + "A";
            }
            else if(counter == 2)
            {
                start = start-column-2;
                outputString = outputString + "B";
            }
            else if(counter == 3)
            {
                start = start-2*column-2;
                outputString = outputString + "C";
            }
            endPos = start;
        }
        counter++;
        if(counter==4) counter = 1; // reset after third piece
    }
    reverse(outputString.begin(), outputString.end());
    cout << outputString << endl;
}

int main()
{
    for(int i=0; i<5; i++)
    {
        int row, column, start, numberBlocked;
        vector <int> blocked;
        string input;
        if(myfile.is_open())
        {
            getline(myfile, input);
        }
        string delimiter = " ";
        int pos = 0;
        string token;
        int tokenCounter = 0;
        while((pos = input.find(delimiter)) > 0)
        {
            token = input.substr(0, pos);
            tokenCounter++;
            if(tokenCounter == 1)
            {
                row = atoi(token.c_str());
            }
            else if(tokenCounter == 2)
            {
                column = atoi(token.c_str());
            }
            else if(tokenCounter == 3)
            {
                start = atoi(token.c_str());
            }
            else if(tokenCounter == 4)
            {
                numberBlocked = atoi(token.c_str());
            }
            else
            {
                blocked.push_back(atoi(token.c_str()));
            }
            input.erase(0, pos+1);
        }
        blocked.push_back(atoi(input.c_str())); //Push the last token into vector
        if(start%column ==1) lefttoright(blocked, start, row, column);
        if(start%column ==0) righttoleft(blocked, start, row, column);
    }
    myfile.close();
    return 0;
}
