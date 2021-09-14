#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;

class sphere
{
    public:
        double radius;
        double pi;
        void volume();
        void surfaceArea();
};

void sphere::volume()
{
    double v = (1.333333)*(pi)*(radius*radius*radius);
    cout << "The volume is: " << v << endl;
}

void sphere::surfaceArea()
{
    double SA = (4)*(pi)*(radius*radius);
    cout << "The surface area is: " << SA << endl;
}

int main()
{
    sphere a;
    a.pi = 3.1415;
    cout << "Radius: ";
    cin >> a.radius;

    a.surfaceArea();
    a.volume();

    return 0;
}
