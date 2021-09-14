#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i;
    double grades[5];
    double average=0;
    cout << "Please enter 5 grades to find class average." << endl;
    for(i=0; i<5; i++)
    {
        cin >> grades[i];
        average= average + (grades[i])/5.0;
    }

    cout << "Your class average is: " << average << endl;

    return 0;
}
