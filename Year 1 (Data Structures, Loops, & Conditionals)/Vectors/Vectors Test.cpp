#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    string input;
    vector <char> data;

    cout << "Enter a stack or queue." << endl;
    getline(cin, input);

    if(input[0]=='S')
    {
        for(int i=0; i<input.size(); i++) //string
        {
            if(input[i]=='X')
            {
                data.pop_back();
            }
            else
            {
                data.push_back(input[i]);
            }
        }
        for(int i=0; i<data.size(); i++)
        {
            cout << data[i];
        }
    }
    else
    {
        if(input[0]=='Q')
        {
            for(int i=0; i<input.size(); i++)
            {
                if(input[i]=='X')
                {
                    data.erase(data.begin());
                }
                else
                {
                    data.push_back(input[i]);
                }
            }
            for(int i=0; i<data.size(); i++)
            {
                cout << data[i];
            }
        }
    }
    return 0;
}
