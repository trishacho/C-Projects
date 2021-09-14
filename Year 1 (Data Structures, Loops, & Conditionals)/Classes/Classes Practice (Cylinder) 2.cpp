#include<iostream>
using namespace std;

class cylinder
{
    private:
        double radius;
        double height;
    public:
        double pi;
        void volume();
        void surfaceArea();
        void setData(double, double);
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

void cylinder::setData(double r, double h)
{
    radius = r;
    height = h;
}

int main()
{
    cylinder a;
    double r, h;
    a.pi = 3.14;
    cout << "Radius: ";
    cin >> r;
    cout << "Height: ";
    cin >> h;

    a.setData(r,h);
    a.volume();
    a.surfaceArea();

    return 0;
}
