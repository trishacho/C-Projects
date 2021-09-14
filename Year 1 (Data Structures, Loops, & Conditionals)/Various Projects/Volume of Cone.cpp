//Trisha Choudhary
//Mr. Greene's class
//Volume of a Cone

#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    cout.setf(ios::showpoint|ios::fixed);
    cout<<setprecision(2);
    const double pi = 3.1415;
    double r, h, V;
    cout << "Enter radius of cone.\n";
    cin >> r;
    cout << "Now enter height of cone.\n";
    cin >> h;
    V= (pi/3)*r*r*h;
    cout << "The volume of your cone is: "<<setw(8)<<V<<endl;
    return 0;
}
