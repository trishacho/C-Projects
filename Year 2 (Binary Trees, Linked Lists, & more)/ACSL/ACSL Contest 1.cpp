//Trisha Choudhary
//12/18/18
//Enloe
//Potter
//Contest 1
//Int-5

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>

using namespace std;

ifstream myfile("S://Public/Potter/iacsl.txt");

int main()
{
    for(int i=0; i<5; i++)
    {
        string input;
        if(myfile.is_open())
        {
            getline(myfile, input);
        }

        int pos = input.find(' ');
        string number = input.substr(0, pos);
        int len = input.size();
        string grouping = input.substr(pos+1, len);
        int groupingNum = atoi(grouping.c_str());

        long long sum = 0;
        for(int i=0; i<=number.size()-groupingNum; i++)
        {
            string temp = " ";
            for(int j=i; j<i+groupingNum; j++)
            {
                temp = temp + number[j];
            }
            sum = sum + atoll(temp.c_str());
        }
        cout << "Sum: " << sum << endl;
    }
    myfile.close();
    return 0;
}
