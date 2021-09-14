#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n;
    cout << "Welcome to the Squares and Averages Calculator." << endl;
    cout << "Please enter a number." << endl;
    cin >> n;

    int a[n];
    int i;
    double total= 0;
    for(i=0; i<n; i++)
    {
        a[i]= (i+1)*(i+1);
        cout << a[i] << "\t";
        total= total + a[i];
    }

    cout << endl;
    cout << "The average of the numbers is: " << total/n << endl;

    return 0;
}
