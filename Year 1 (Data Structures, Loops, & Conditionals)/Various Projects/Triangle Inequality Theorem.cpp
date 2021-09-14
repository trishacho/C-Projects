//Ms. Davis's Class 1(B)
//Trisha Choudhary
//Triangle Inequality Theorem

#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    int c;
    cout << "Hello! Welcome to the Triangle Inequality Theorem Calculator." << endl;
    cout << "Please enter the 3 values." << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    if ((a<(b+c))&&(b<(a+c))&&(c<(b+a)))
    {
        cout << "Your values make a triangle." << endl;
    }
    else
    {
        cout << "Your values do not make a triangle." << endl;
    }
    if (((a*a)+(b*b)==(c*c))&&((a<(b+c))&&(b<(a+c))&&(c<(b+a))))
    {
        cout << "Your values make a right triangle." << endl;
    }
    else if (((a*a)+(b*b)<(c*c))&&((a<(b+c))&&(b<(a+c))&&(c<(b+a))))
    {
        cout << "Your values make an obtuse triangle." << endl;
    }
    else if (((a*a)+(b*b)>(c*c))&&((a<(b+c))&&(b<(a+c))&&(c<(b+a))))
    {
        cout << "Your values make an acute triangle." << endl;
    }

    return 0;
}
