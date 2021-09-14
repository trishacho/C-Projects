#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n;
    cout << "Hello! Welcome to Multiplication Grid." << endl;
    cout << "Please enter a number." << endl;
    cin >> n;

    int i, j;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << i*j << "\t";
        }
        cout << endl;
    }
    return 0;
}
