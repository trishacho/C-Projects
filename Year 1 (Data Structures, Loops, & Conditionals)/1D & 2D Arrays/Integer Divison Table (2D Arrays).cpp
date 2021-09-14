#include<iostream>

using namespace std;

int main()
{
    int i, j, k;
    int a[6][6];
    int seed;
    int row, column;
    a[0][0] = -1;

    cout << "Please input a seed." << endl;
    cin >> seed;
    cout << "Please input a row and column number (1-5)." << endl;
    cin >> row >> column;

    for(k=1; k<=5; k++)
    {
        a[0][k]=seed+(k-1);
        a[k][0]=a[0][k];
    }

    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            a[i][j] = a[0][j]/a[i][0];
        }
    }
    cout << "Output= " << a[row][column];
    return 0;
}
