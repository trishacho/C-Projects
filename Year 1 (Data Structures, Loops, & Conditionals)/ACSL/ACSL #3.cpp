#include<iostream>
#include<string>

using namespace std;

int a[4][4];
int atemp[4][4];

//Find commas in substring
string findSubString(string cuatro, int i)
{
    int length = cuatro.size();
    int pos1 = cuatro.find(',');
    string sub = cuatro.substr(0, pos1);
    int lensub = sub.length();

    return sub;
}

//Filling the array from left to right
void fillArray(string substring, int rowNumber)
{
    int array_position = 3; // Start with the element
    for (int i = substring.size()-1; i >= 0; i--)
    {
        int entry = substring[i];
        a[rowNumber][array_position] = entry-'0';
        array_position--;
    }
}

void runRules(int posi, int posj)
{
    int tempi, tempj;
    //Store char array into int array
    for(int i =0 ; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            atemp[i][j] = a[i][j];
        }
    }
    for(int i = 0; i < 6; i++)
    {
        //Row 1 has a boundary problem if entry is 2 (2 moves up)
        if (posi == 0 && atemp[posi][posj]==2)
        {
            tempi = posi;
            tempj = posj;
            if (posj == 0)posj = 3;
            if (posj == 3) posj = 0;
            if (posj ==1) posi = 3;
            if (posj == 2) posi = 3;
            atemp[tempi][tempj] = atemp[tempi][tempj]+1;
        }
        else if(posi == 3 && atemp[posi][posj] == 3)
        {
            //Last row has a boundary problem if entry is 3 (3 moves down)
            tempi = posi;
            tempj = posj;
            if (posj == 0)posj = 3;
            if (posj == 3) posj = 0;
            if (posj ==1) posi = 0;
            if (posj == 2) posi = 0;
            atemp[tempi][tempj] = atemp[tempi][tempj]+1;
            if (atemp[tempi][tempj] == 4) atemp[tempi][tempj]=0;
        }
        else if(posj == 0  && atemp[posi][posj] == 1)
        {
            //First column has a boundary problem if entry is 1 (1 moves left)
            tempi = posi;
            tempj = posj;
            posj = 3;
            atemp[tempi][tempj] = atemp[tempi][tempj]+1;
        }
        else if(posj == 3  && atemp[posi][posj] == 0)
        {
            //Last column has a boundary problem if entry is 0 (0 moves right)
            tempi = posi;
            tempj = posj;
            posj = 0;
            atemp[tempi][tempj] = atemp[tempi][tempj]+1;
        }
        else
        {
            //No boundaries, normal, inside the middle of the array
            tempi = posi;
            tempj = posj;
            if(atemp[posi][posj]==0)
            {
                posj = posj +1;
            }
            else if (atemp[posi][posj]==1)
            {
                posj = posj-1;
            }
            else if (atemp[posi][posj]==2)
            {
                posi = posi-1;
            }
            else if (atemp[posi][posj]==3)
            {
                posi = posi+1;
            }
            atemp[tempi][tempj] = atemp[tempi][tempj]+1;
            if(atemp[tempi][tempj] == 4) atemp[tempi][tempj] = 0;
        }
    }
    cout << posi+1 << "," << posj+1 << endl;
}

int main()
{
    string uno;
    string input1, input2, input3, input4, input5;
    int dos, tres;

    cout << "Please enter the array values and 5 lines of position." << endl;
    getline(cin, uno);
    getline(cin, input1);
    getline(cin, input2);
    getline(cin, input3);
    getline(cin, input4);
    getline(cin, input5);

    //Find the first substring
    int len1 = uno.size();
    int pos1 = uno.find(',');
    string substring1 = uno.substr(0,pos1);

    //Find the rest of the string from the original string. Second Part.
    string newString1 = uno.substr(pos1+1, len1-1);
    int len2 = newString1.size();
    int pos2 = newString1.find(',');
    string substring2 = newString1.substr(0,pos2);

    //Find the rest of the string from the second string above. Third Part
    string newString2 = newString1.substr(pos2+1, len2-1);
    int len3 = newString2.size();
    int pos3 = newString2.find(',');
    string substring3 = newString2.substr(0,pos3);

    //Find the rest of the last bit and note that there is no comma at the end
    string substring4 = newString2.substr(pos3+1, len3-1);

    //Set all entries to zero
    for (int i=0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
           a[i][j] = 0;
        }
    }

    //Fill out array with values from substring
    fillArray(substring1, 0);
    fillArray(substring2, 1);
    fillArray(substring3, 2);
    fillArray(substring4, 3);

    cout << "OUTPUT:" << endl;
    //Now run through the logic
    int pos_i = input1[0]-'0';
    int pos_j = input1[2]-'0';
    runRules(pos_i-1, pos_j-1);

    pos_i = input2[0]-'0';
    pos_j = input2[2]-'0';
    runRules(pos_i-1, pos_j-1);

    pos_i = input3[0]-'0';
    pos_j = input3[2]-'0';
    runRules(pos_i-1, pos_j-1);

    pos_i = input4[0]-'0';
    pos_j = input4[2]-'0';
    runRules(pos_i-1, pos_j-1);

    pos_i = input5[0]-'0';
    pos_j = input5[2]-'0';
    runRules(pos_i-1, pos_j-1);

    return 0;
}
