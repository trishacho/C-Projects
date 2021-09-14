#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i;
    double grades[10];
    cout << "Please enter 10 grades." << endl;
    for(i=1; i<11; i++)
    {
        cin >> grades[i];
    }
    cout << "Please enter the number of which student's grade you want to see." << endl;
    cin >> i;
    cout << "The student's grade is: " << grades[i];

    return 0;
}
