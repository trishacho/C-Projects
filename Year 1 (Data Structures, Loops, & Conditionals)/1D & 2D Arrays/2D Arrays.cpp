#include<iostream>

using namespace std;

int main()
{
    int i, j;
    //int k=0;
    //int a[k];
    //for(i=0; i<=5; i++)
    //{
        //for(j=0; j<=5; j++)
        //{
            //a[k]=(i+1)*(j+1);
            //cout << a[k] << " ";
            //cout << (i+1)*(j+1) << " " << endl;
        //}
        //cout << endl;
    //}

    //Arrays within arrays: when you're trying to access a specific element in a row in an array
    //i represents rows, j represents columns
    //a[2][3] = 3rd row, 4th column

    int a[5][5]; //if you don't know how big the array is, put a random number; if you do, put the number
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            a[i][j] = (i+1)*(j+1);
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}
