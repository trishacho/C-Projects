#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i;
    double cPlusPlus[5];
    double Math[5];
    double English[5];
    double cPlusPlusAvg, MathAvg, EnglishAvg;
    double average=0;

    cout << "Please enter 5 grades for C++." << endl;
    for(i=1; i<=5; i++)
    {
        cin >> cPlusPlus[i];
    }
    cout << "Please enter 5 grades for Math." << endl;
    for(i=1; i<=5; i++)
    {
        cin >> Math[i];
    }
    cout << "Please enter 5 grades for English." << endl;
    for(i=1; i<=5; i++)
    {
        cin >> English[i];
    }
    cout << "Please enter the number of which student's grades you want to see." << endl;
    cin >> i;
    average= (cPlusPlus[i] + Math[i] + English[i])/3.0;
    cout << "The student's grades are: " << cPlusPlus[i]<< ", " << Math[i] << ", " << English[i] << endl;
    cout << "The average of the student's grades are: " << average << endl;

    if((average>=90) && (average<=100))
    {
        cout << "This student has an A." << endl;
    }
    else if((average>=80) && (average<90))
    {
        cout << "This student has a B." << endl;
    }
    else if((average>=70) && (average<80))
    {
        cout << "This student has a C." << endl;
    }
    else if((average>=60) && (average<70))
    {
        cout << "This student has a D." << endl;
    }
    else if(average<60)
    {
        cout << "This student has an F." << endl;
    }

    return 0;
}
