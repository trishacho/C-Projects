#include <iostream>
#include <string>
#include<vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct cityData
{
    string name;
    int temp;
};

vector <cityData> a(100);
int counter = 0;

void bubbleSort(vector <cityData>& vecname, int vecsize)
{
    for(int i=0; i<vecsize; i++)
    {
        for(int j=i+1; j<vecsize; j++)
        {
            string tempVar1 = vecname[i].name;
            if(vecname[i].temp < vecname[j].temp)
            {
                vecname[i].name = vecname[j].name;
                vecname[j].name = tempVar1;
            }
        }
    }

    for(int i=0; i<vecsize; i++)
    {
        for(int j=i+1; j<vecsize; j++)
        {
            int tempVar2 = vecname[i].temp;
            if(vecname[i].temp < vecname[j].temp)
            {
                vecname[i].temp = vecname[j].temp;
                vecname[j].temp = tempVar2;
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
            a.push_back(cityData());

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

        for (int i=0; i<counter; i++)
        {
            cout << a[i].name << " ";
            cout << a[i].temp << endl;
        }
    }
    return 0;
}
