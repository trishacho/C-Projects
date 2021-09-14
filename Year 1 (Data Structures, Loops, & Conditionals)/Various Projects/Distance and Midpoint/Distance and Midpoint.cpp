//Trisha Choudhary
//Ms. Davis's class
//Distance and Midpoint
//Slope

#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

double distanceEq(int x1, int y1, int x2, int y2)
{
    double d= sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return d;
}

double averageEq(int a, int b)
{
    double average= (a+b)/2.0;
    return average;
}

double slopeEq(int x1, int y2, int y1, int x2)
{
    double slope = ((y2-y1)/double (x2-x1));
    return slope;
}

void output(double dist, double midX, double midY, double slp)
{
    cout.setf(ios::showpoint|ios::fixed);
    cout << "Your distance is: " << setw(10) << dist << endl;
    cout << "Your midpoint is: " << setw(10) << midX << ", " << midY << endl;
    cout << "Your slope is: " << setw(10) << slp << endl;
}

int main ()
{
    int ax, ay, bx, by;
    double dist;
    double midX, midY;
    double slp;
    cout << "Enter the coordinates of the first point: " << endl;
    cin >> ax;
    cin >> ay;
    cout << "Enter the coordinates of the second point: " << endl;
    cin >> bx;
    cin >> by;
    dist = distanceEq(ax, ay, bx, by);
    midX = averageEq(ax, bx);
    midY = averageEq(ay, by);
    slp = slopeEq(ax, by, ay, bx);
    output(dist, midX, midY, slp);
}

