#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

void printVec(vector <char> v)
{
    for(int i=0; i<v.size(); i++)
    {
      cout << v[i];
    }
    cout << endl;
}

int main()
{
    string input;
    vector <char> data;
    vector <char> output;
    int counter = 1;

    //get input and erase spaces
    cout << "Please enter your input 5 times." << endl;
//    for(int i=0; i<5; i++)
//    {
        getline(cin, input);
        input.erase(remove(input.begin(), input.end(), ' '), input.end());

        //change char to int and separate numberN and word
        char numbe
        r = input[0];
        int numberN = number - '0';
        input = input.substr(1, input.size());

        //uppercase alphabets
        for(int i=0;i<input.size();i++)
        {
            if(input[i]>90)
            {
                input[i]=input[i]-32;
            }
        }

        //order alphabets and count changes
        char tempChar1;
        char tempChar2;
        for(int i=0; i<input.size(); i++)
        {
            data.push_back(input[i]);
            if(i > numberN-1)
            {
                tempChar1 = data[numberN-1];
            }
            sort(data.begin(),data.end());
            if(i > numberN-1)
            {
                tempChar2 = data[numberN-1];
                if(tempChar2 != tempChar1)
                {
                    counter++;
                }
            }
        }
        cout << counter << endl;
//    }
    return 0;
}
