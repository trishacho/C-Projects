//Trisha Choudhary
//Mrs. Patnaik's class
//Simple Interest

#include <iostream>
#include <math.h>

using namespace std;

void input(int&a, int &b)
{
    cout << "Welcome to the multiplication table calculator!" << endl;
    cout << "Please enter a number and then the number of times you want to multiply it." << endl;
    cin>> a >> b;
}

//For-Loop

//int main()
//{
    //int a, b;
    //input(a, b);
    //int i=1;
    //int total=0;
    //for(int i=1; i<= b; i++)
    //{
        //cout << "Value: " << a*i << endl;
    //}

    //return 0;
//}

//While Loop

//int main()
//{
    //int a, b;
    //input (a, b);
    //int i= 1;
    //while (i<=b)
    //{
        //cout << "Value: " << a*i << endl;
        //i++;
    //}

    //return 0;
//}

//Do-While Loop

int main()
{
    int a, b;
    input (a, b);
    int i= 1;
    do
    {
        cout << "Value: " << a*i << endl;
        i++;
    } while (i<=b);

    return 0;
}
