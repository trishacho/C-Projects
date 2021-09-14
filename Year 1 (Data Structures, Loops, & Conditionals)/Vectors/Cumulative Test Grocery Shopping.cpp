#include <iostream>
#include <string>
#include<vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    vector <string> grocery;
    string input;

    //read input from a file
    ifstream myfile;
    myfile.open("patnaikList.txt", ifstream::in);
    if(!myfile)
    {
        cout << "Cannot open patnaikList.txt" << endl;
    }
    else
    {
        getline(myfile, input);
        while(myfile)
        {
            getline(myfile, input);

            //first letter capitalized
            input[0] = toupper(input[0]);

            //push back input into a vector
            grocery.push_back(input);

            //sort input
            for(int i=0; i<grocery.size(); i++)
            {
                for(int j=i+1; j<grocery.size(); j++)
                {
                    if(grocery[i]>grocery[j])
                    {
                        input = grocery[i];
                        grocery[i] = grocery[j];
                        grocery[j] = input;
                    }
                }
            }
        }
    }
    for(int i=0; i<grocery.size(); i++)
    {
        cout << grocery[i] << endl;
    }
    return 0;
}
