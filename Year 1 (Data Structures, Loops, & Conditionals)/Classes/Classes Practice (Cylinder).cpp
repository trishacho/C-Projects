#include<iostream>
using namespace std;

class cylinder
{
    public:
        double radius;
        double height;
        double pi;
        void volume();
        void surfaceArea();
};

void cylinder::volume()
{
    double v = (pi)*(radius*radius)*(height);
    cout << "The volume is: " << v << endl;
}

void cylinder::surfaceArea()
{
    double SA = ((2)*(pi)*(radius)*(height)) + ((2)*(pi)*(radius*radius));
    cout << "The surface area is: " << SA << endl;
}

int main()
{
    cylinder a;
    a.pi = 3.14;
    cout << "Radius: ";
    cin >> a.radius;
    cout << "Height: ";
    cin >> a.height;

    a.volume();
    a.surfaceArea();

    return 0;
}
