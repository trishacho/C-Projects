#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct cityData
{
    string name;
    int temp;
};

cityData a[100];
int counter = 0;

void bubbleSort(cityData arrayname[], int arraysize) //add YOUR bubble sort logic
{
    for(int i=0; i<arraysize; i++)
    {
        for(int j=i+1; j<arraysize; j++)
        {
            string tempVar1 = arrayname[i].name;
            if(arrayname[i].temp < arrayname[j].temp)
            {
                arrayname[i].name = arrayname[j].name;
                arrayname[j].name = tempVar1;
            }
        }
    }

    for(int i=0; i<arraysize; i++)
    {
        for(int j=i+1; j<arraysize; j++)
        {
            int tempVar2 = arrayname[i].temp;
            if(arrayname[i].temp < arrayname[j].temp)
            {
                arrayname[i].temp = arrayname[j].temp;
                arrayname[j].temp = tempVar2;
            }
        }
    }
}

int main()
{
    string strg;
    ifstream myfile;

    myfile.open("CityData.txt",ifstream::in);
    if(!myfile)
    {
        cout << "Cannot open CityData.txt" << endl;
    }
    else
    {
        getline(myfile,strg);
        while(myfile)
        {
            int pos = strg.find(' ');
            int len = strg.size();

            string num = strg.substr(pos+1,len-pos);
            a[counter].temp = atoi(num.c_str());
            a[counter].name = strg.substr(0,pos);
            getline(myfile, strg);
            counter++;

            bubbleSort(a, counter);
        }
        cout << endl;

        for(int i=0; i<counter; i++)
        {
            cout << a[i].name << " ";
            cout << a[i].temp << endl;
        }
    }
    return 0;
}
