#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "While Loop" << endl;
    int j;
    int i=1;
    int n=5;
    while(i<=n)
    {
        j=1;
        while(j<=n)
        {
            cout << j;
            j++;
        }
        i++;
        cout << endl;
    }

    cout << "Do While Loop" << endl;
    j;
    i=1;
    n=5;
    do
    {
        j=1;
        do
        {
            cout << j;
            j++;
        } while(j<=n);
        i++;
        cout << endl;
    } while(i<=n);

    cout << "For Loop" << endl;
    j, i;
    n=5;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
