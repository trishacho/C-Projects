#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int i, j;
    int n;
    cout << "Hello! Welcome to size of a box." << endl;
    cout << "Please enter what size you want your box to be." << endl;
    cin >> n;

    for(i=1; i<=(n+2); i++)
        {
            if(i==1||i==n+2)
            {
                cout << "+";
                for(j=1; j<=n; j++)
                {
                    cout << "^ ";
                }
                cout << "+" << endl;
            }
            else
            {
                cout << "|";
                for(j=1; j<=n; j++)
                    {
                        cout << "  ";
                    }
            cout << "|" << endl;
            }
        }

    return 0;
}
