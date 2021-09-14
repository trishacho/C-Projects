//Creating vectors
//Read in four student names from the console and create a random ID for each student
#include<iostream>
#include<iomanip>
#include<vector>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    vector <string> students; //Vector of strings
    vector <int> id(4,0); //Vector filled with four integers with the value of 0
    string name;

    //Input the student's names. Use pushback to add to the vector
    for(int i=0; i<4; i++)
    {
        cout << "Enter a student's name." << endl;
        cin >> name;
        students.push_back(name);
    }
    //Create a randomly generated four digit Student ID
    //Pushback is not needed to add to the vector because we declare it as having 4 entries

    srand(time(NULL)); //Initialize a random seed
    for(int i=0; i<4; i++)
    {
        id[i] = rand()%10000+1;
    }

    cout << endl << setw(12) << "Students" << setw(6) << "ID" << endl;

    for(int i=0; i<4; i++)
    {
        cout << setw(12) << students[i] << setw(6) << id[i] << endl;
    }

    return 0;
}
