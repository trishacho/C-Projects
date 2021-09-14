#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n, m;
    int i;

    cout << "Welcome to the Finding Multiples of a Number Calculator." << endl;
    cout << "Please enter a number that you want to find the multiples of." << endl;
    cin >> n;
    cout << "Please enter how many multiples of the number you would like to see." << endl;
    cin >> m;

    int a[m];
    int total= 0;
    for(i=1; i<=m; i++)
    {
        total= total + n;
        a[i]= total;
        cout << a[i] << "\t";
    }

    return 0;
}
