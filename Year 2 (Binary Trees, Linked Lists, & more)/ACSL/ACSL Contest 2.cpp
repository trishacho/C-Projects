#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>

using namespace std;

ifstream myfile("S://Public/CS/int2.txt");

string commonStrings(string one, string two)
{
    string newString;
    for(int i=0; i<one.size(); i++)
    {
        int pos = two.find(one[i]);
        if(pos >= 0)
        {
            newString = newString + one[i];
            two = two.substr(pos+1, two.size());
        }
    }
    return newString;
}

int main()
{
    for(int i=0; i<5; i++)
    {
        string input;
        if(myfile.is_open())
        {
            getline(myfile, input);
        }
        int space = input.find(' ');
        string input1 = input.substr(0, space);
        string input2 = input.substr(space+1, input.size());

        string substring1 = commonStrings(input1, input2);
        string substring2 = commonStrings(input2, input1);

        reverse(input1.begin(), input1.end());
        reverse(input2.begin(), input2.end());
        string substring3 = commonStrings(input1, input2);
        string substring4 = commonStrings(input2, input1);

        sort(substring1.begin(), substring1.end());
        sort(substring2.begin(), substring2.end());
        sort(substring3.begin(), substring3.end());
        sort(substring4.begin(), substring4.end());

        string newString1 = commonStrings(substring1, substring2);
        string newString2 = commonStrings(substring3, substring4);

        string newString = commonStrings(newString1, newString2);
        if(newString.empty())
        {
            cout << "NONE";
        }
        else
        {
            for(int i=0; i<newString.size()-1; i++)
            {
                while(newString[i] == newString[i+1])
                {
                    int pos = newString.find(newString[i]);
                    newString.replace(pos, 1, "");
                }
            }
        }
        cout << newString << endl;
    }
    myfile.close();
    return 0;
}
