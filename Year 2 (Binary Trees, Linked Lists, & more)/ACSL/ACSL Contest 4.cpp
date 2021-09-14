#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

ifstream myfile("F://int4.txt");

void printVec(vector <int> vecInput)
{
    for(int i=0; i<vecInput.size(); i++)
    {
        cout << vecInput[i] << endl;
    }
}

void check(string input)
{
    vector <int> vecStr;
    for (int i=input.size()-1; i>=0; i--) //going backwards
    {
        if(isdigit(input[i])) //check for operand
        {
            vecStr.push_back(input[i]-'0');
        }
        else //check for operator
        {
            int firstElement = vecStr[vecStr.size()-1];
            int secondElement = vecStr[vecStr.size()-2];
            char operand = input[i];
            if(operand == '+')
            {
                int total = firstElement + secondElement;
                vecStr.erase(vecStr.end()-2, vecStr.end()); //get rid of elements used
                vecStr.push_back(total); //push the total to the vector
            }
            else if(operand == '-')
            {
                int total = firstElement - secondElement;
                vecStr.erase(vecStr.end()-2, vecStr.end());
                vecStr.push_back(total);
            }
            else if(operand == '*')
            {
                int total = secondElement*firstElement;
                vecStr.erase(vecStr.end()-2, vecStr.end());
                vecStr.push_back(total);
            }
            else if (operand == '@')
            {
                int thirdElement = vecStr[vecStr.size()-3]; //trinary operator
                vecStr.erase(vecStr.end()-3, vecStr.end()); //Get rid of the element used
                int total;
                if(firstElement > 0)
                {
                    total = secondElement;
                }
                else
                {
                    total = thirdElement;
                }
                vecStr.push_back(total);
            }
            else if(operand == '>')
            {
                int thirdElement = vecStr[vecStr.size()-3];
                vecStr.erase(vecStr.end()-3, vecStr.end());
                int total = thirdElement;
                //Find max of 3 elements
                if(secondElement > total)
                {
                    total = secondElement;
                }
                if(firstElement > total)
                {
                    total = firstElement;
                }
                vecStr.push_back(total);
            }
            else
            {
                cout << "Illegal operation." << endl;
            }
        }
    }
    printVec(vecStr); //Prints answer
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
        input.erase(remove(input.begin(), input.end(), ' '), input.end());  //Removing spaces
        check(input);
    }
    myfile.close();
    return 0;
}
