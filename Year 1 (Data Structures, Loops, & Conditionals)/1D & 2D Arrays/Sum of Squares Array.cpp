#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i;
    int n;
    int total=0;
    double numbers[10];
    cout << "Please enter 10 numbers." << endl;
    for(i=0; i<10; i++)
    {
        cin >> numbers[i];
        total = total + numbers[i]*numbers[i];
    }

    cout << "The numbers squared are: " << total << endl;

    return 0;
}
