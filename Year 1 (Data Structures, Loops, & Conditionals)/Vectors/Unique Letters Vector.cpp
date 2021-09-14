#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector <char> struggle;
    string word;
    int i, j;

    cout << "Please enter a word." << endl;
    getline(cin, word);

    struggle.push_back(word[0]);

    for(i=0; i <= word.size(); i++) //string
    {
        for(j=0; j <= struggle.size(); j++) //array
        {
            if(word[i]==struggle[j])
            {
                break;
            }
            else
            {
                if(j==struggle.size())
                {
                    struggle.push_back(word[i]);
                    break;
                }
            }
        }
    }

    for(i=0;  i < struggle.size(); i++)
    {
        cout << struggle[i];
    }

    return 0;
}
