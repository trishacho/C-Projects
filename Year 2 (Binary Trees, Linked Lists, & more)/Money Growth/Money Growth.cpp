#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>

using namespace std;

void input(double &p, double &r, int &n, double &goal)
{
    cout << "Principle: ";
    cin >> p;
    cout << "Rate: ";
    cin >> r;
    cout << "Compounded By: ";
    cin >> n;
    cout << "Goal: ";
    cin >> goal;
}

double twoDecimals(double x)
{
    int z; //z is an int so it can get rid of redundant decimals after multiplying
    double y;
    z = (x+0.005)*100; //checks if third position after decimal is rounded up or down
    y = z/100.0; //divide it to move the decimal back into place
    return y;
}

double calculation(double p, double r, int n, int t)
{
    r = r/100;
    double base = (1+(r/n));
    double exp = n*t;
    double amount = p*pow(base, exp);
    return amount;
}

void output(double &p, double &r, int &n, double &goal)
{
    vector <double> output;
    int t = 0;
    double answer = p;
    //While comparing only use two decimal places
    double rounded = twoDecimals(p);
    while(t<=10 && rounded < goal)
    {
        answer = calculation(p, r, n, t);
        output.push_back(answer);
        rounded = twoDecimals(answer);

        t++;
    }

    cout << endl;
    cout << setw(10) << left << "Year";
    cout << setw(10) << left << "Amount" << endl;

    for(int i=0; i<output.size(); i++)
    {
        cout.setf(ios::showpoint|ios::fixed);
        cout << setprecision(2) << setw(10) << left << i << output[i] << endl;
    }
    if(rounded >= goal)
    {
        cout << "Congrats, goal met. You have $" << rounded-goal << " left." << endl;
    }
    else
    {
        cout << "Goal not met, you still need $" << goal-answer << "." << endl;
    }
}


int main()
{
    double principle, rate;
    int n;
    double goal;

    input(principle, rate, n, goal);
    output(principle, rate, n, goal);

    cout << calculation(500, 5, 20, 1);

    return 0;
}
