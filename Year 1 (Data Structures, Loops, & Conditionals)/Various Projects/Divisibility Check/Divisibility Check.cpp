#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int a, b;
    int c;
    cout << "Enter two numbers that you want to multiply." << endl;
    cin >> a >> b;
    cout << "Enter the number you want to divide the product by." << endl;
    cin >> c;

    if ((a*b)%c == 0)
    {
        cout << "Your numbers are divisible." << endl;
    }
    else
    {
        cout << "Your numbers are not divisible. Please retry." << endl;
    }

    return 0;
}
