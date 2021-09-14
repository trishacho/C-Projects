#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i;
    double cPlusPlus[10];
    double Math[10];
    double English[10];

    cout << "Please enter 10 grades for C++." << endl;
    for(i=1; i<11; i++)
    {
        cin >> cPlusPlus[i];
    }
    cout << "Please enter 10 grades for Math." << endl;
    for(i=1; i<11; i++)
    {
        cin >> Math[i];
    }
    cout << "Please enter 10 grades for English." << endl;
    for(i=1; i<11; i++)
    {
        cin >> English[i];
    }

    cout << "Please enter the number of which student's grades you want to see." << endl;
    cin >> i;
    cout << "The student's grades are: " << cPlusPlus[i]<< ", " << Math[i] << ", " << English[i];

    return 0;
}
