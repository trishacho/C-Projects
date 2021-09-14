//Ms. Davis's class 1(B)
//Trisha Choudhary
//Standard Deviation

#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

void input(int &a, int&b, int&c, int&d, int&e)
{
    cout << "Welcome to the Standard Deviation Calculator!" << endl;
    cout << "Please enter 5 values." << endl;
    cin >> a >> b >> c >> d >> e;
    cout << "Calculating..." << endl;
}

double meanEq(double x1, double x2, double x3, double x4, double x5)
{
    double mean= (x1+x2+x3+x4+x5)/5.0;
    return mean;
}

double diffSq(double mean, double x)
{
    return (x-mean)*(x-mean);
}

double StdDevEq(double a, double b, double c, double d, double e)
{
    double s1, s2, s3, s4, s5;
    double m;
    m= meanEq(a, b, c, d, e);
    s1= diffSq(a,m);
    s2= diffSq(b,m);
    s3= diffSq(c,m);
    s4= diffSq(d,m);
    s5= diffSq(e,m);
    double SD= sqrt(meanEq(s1, s2, s3, s4, s5));
    return SD;
}

void output(double mean, double SD)
{
    cout.setf(ios::showpoint|ios::fixed);
    cout << setprecision(3);
    if (SD<=10)
    {
        cout << "Your standard deviation is low." << endl;
    }
    else if ((SD>10)&&(SD<50))
    {
        cout << "Your standard deviation is in the middle." << endl;
    }
    else if (SD>=50)
    {
        cout << "Your standard deviation is high." << endl;
    }
    cout << "Your mean is: " << mean << endl;
    cout << "Your standard deviation is: " << SD << endl;
}

int main()
{
    int a, b, c, d, e;
    double mean;
    double SD;
    input(a, b, c, d, e);
    mean= meanEq(a, b, c, d, e);
    SD= StdDevEq(a, b, c, d, e);
    output (mean, SD);

    return 0;
}
