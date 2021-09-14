#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int main()
{
    ifstream myfile;
    string number;
    int ctr = 0;
    int arr[10];

    myfile.open("data.txt", ifstream::in);

    if(!myfile)
        cout << "Error" << endl;
    else
    {
        getline(myfile, number);
        while(myfile)
        {
            arr[ctr] = atoi(number.c_str());
            cout << arr[ctr] << endl;
            getline(myfile, number);
            ctr++;
        }
    }
    return 0;
}
