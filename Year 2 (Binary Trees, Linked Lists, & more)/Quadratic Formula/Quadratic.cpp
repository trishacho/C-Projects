#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

ifstream myfile("S:\\Public\\Potter\\Quad\\Quad5.txt");

//Find GCD of 2 numbers
int GCD2(int a, int b)
{
    int divisor = 1;
    int i = 1;

    while(i<=abs(b) && i<=abs(a))
    {

        if(abs(b)%i==0 && abs(a)%i==0)
        {
            divisor = i;
        }
        i++;
    }

    return divisor;
}

//Find GCD of 3 numbers
int GCD3(int b, int outsideRoot, int a)
{
   int divisor = 1;
   int i = 1;

   while(i<=abs(b) && i<=outsideRoot && i<=abs((2*a)))
    {
        if(abs(b)%i==0 && outsideRoot%i==0 && abs((2*a))%i==0)
        {
            divisor = i;
        }
        i++;
    }

    return divisor;
}

//all simplification processes
void simplify(int a, int b, int discriminant)
{
    int insideRoot = discriminant;
    int outsideRoot = 1;
    int start = 2;

    //simplify sqrt with real solutions
    if(discriminant > 0)
    {
        while((start*start) <= insideRoot)
        {
            if(insideRoot%(start*start) == 0)
            {
                insideRoot = insideRoot/(start*start);
                outsideRoot = outsideRoot*start;
            }
            else
            {
                start++;
            }
        }
    }

    //one solution
    if(discriminant == 0)
    {
        if(-b%(2*a) == 0)
        {
            cout << -b/(2*a) << endl;
        }
        else
        {
            cout << -b/(GCD2((2*a), b)) << "/" << (2*a)/(GCD2((2*a), b)) << endl;
        }
    }

    //simplify sqrt with two imaginary solutions
    if(discriminant < 0)
    {
        insideRoot = -insideRoot;
        while((start*start) <= insideRoot)
        {
            if(insideRoot%(start*start) == 0)
            {
                insideRoot = insideRoot/(start*start);
                outsideRoot = outsideRoot*start;
            }
            else
            {
                start++;
            }
        }
    }

    int divisor;
    //removing sqrt symbol if sqrt(1)
    if(insideRoot == 1)
    {
        //find GCD = what to divide by
        divisor = GCD2((2*a), b);
        //outputs with 2 real solutions
        if(discriminant > 0)
        {
            //removing the denominator if denominator=1
            if((2*a)/divisor == 1)
            {
                cout << (-b/divisor) + (outsideRoot/divisor) << ", ";
                cout << (-b/divisor) - (outsideRoot/divisor) << endl;
            }
            else
            {
                //if denominator is not 1, then add or subtract numerator and divide top and bottom by GCD to simplify fraction
                int numSum1 = -b + outsideRoot;
                int numSum2 = -b - outsideRoot;
                int denom = (2*a);

                int GCDnumSum1 = GCD2(numSum1, denom);
                int GCDnumSum2 = GCD2(numSum2, denom);

                int numerator1 = numSum1/GCDnumSum1;
                int numerator2 = numSum2/GCDnumSum2;
                int denominator1 = denom/GCDnumSum1;
                int denominator2 = denom/GCDnumSum2;

                //after simplification, if denominator becomes 1 again
                if(denominator1 == 1)
                {
                    cout << numerator1 << ", ";
                    cout << numerator2 << "/" << denominator2 << endl;
                }
                else if(denominator2 == 1)
                {
                    cout << numerator1 << "/" << denominator1 << ", ";
                    cout << numerator2 << endl;
                }
                else if(denominator1 == 1 && denominator2 == 1)
                {
                    cout << numerator1 << ", ";
                    cout << numerator2 << endl;
                }
                else
                {
                    cout << numerator1 << "/" << denominator1 << ", ";
                    cout << numerator2 << "/" << denominator2 << endl;
                }
            }
        }
        else if(discriminant < 0) //outputs with two imaginary solutions
        {
            //remove denominator if denominator=1
            if((2*a)/divisor == 1)
            {
                //remove 1 if outsideRoot = 1
                if(outsideRoot/divisor == 1)
                {
                    cout << (-b/divisor) << "+" << "i" << ", ";
                    cout << (-b/divisor) << "-" << "i" << endl;
                }
                else
                {
                    cout << (-b/divisor) << "+" << (outsideRoot/divisor) << "i" << ", ";
                    cout << (-b/divisor) << "-" << (outsideRoot/divisor) << "i" << endl;
                }
            }
            else //if denominator is not 1
            {
                //remove 1 if outsideRoot = 1
                if(outsideRoot/divisor == 1)
                {
                    cout << (-b/divisor) << "+" << "i/" << ((2*a)/divisor) << ", ";
                    cout << (-b/divisor) << "-" << "i/" << ((2*a)/divisor) << endl;
                }
                else
                {
                    cout << "(" << (-b/divisor) << "+" << (outsideRoot/divisor) << "i)/" << ((2*a)/divisor) << ", ";
                    cout << "(" << (-b/divisor) << "-" << (outsideRoot/divisor) << "i)/" << ((2*a)/divisor) << endl;
                }
            }
        }
    }
    else //if insideRoot is anything besides 1 or 0
    {
        //find GCD of all 3 values = what to divide by
        divisor = GCD3(b, outsideRoot, a);
        //outputs with two real solutions
        if(discriminant > 0)
        {
            //if denominator = 1, remove denominator
            if((2*a)/divisor == 1)
            {
                //if outsideRoot = 1, remove 1
                if(outsideRoot/divisor == 1)
                {
                    cout << -b/divisor << "+" << "{" << insideRoot << "}" << ", ";
                    cout << -b/divisor << "-" << "{" << insideRoot << "}" << ", ";
                }
                else
                {
                    cout << "(" << -b/divisor << "+" << outsideRoot/divisor << "{" << insideRoot << "}" << ")" << ", ";
                    cout << "(" << -b/divisor << "-" << outsideRoot/divisor << "{" << insideRoot << "}" << ")" << endl;
                }
            }
            else //if denominator is not 1
            {
                //if outsideRoot = 1, remove 1
                if(outsideRoot/divisor == 1)
                {
                    cout << "(" << -b/divisor << "+" << "{" << insideRoot << "}" << ")" << "/" << (2*a)/divisor << ", ";
                    cout << "(" << -b/divisor << "-" << "{" << insideRoot << "}" << ")" << "/" << (2*a)/divisor << endl;
                }
                else
                {
                    cout << "(" << -b/divisor << "+" << outsideRoot/divisor << "{" << insideRoot << "}" << ")" << "/" << (2*a)/divisor << ", ";
                    cout << "(" << -b/divisor << "-" << outsideRoot/divisor << "{" << insideRoot << "}" << ")" << "/" << (2*a)/divisor << endl;
                }
            }
        }
        else if(discriminant < 0) //outputs with two imaginary solutions
        {
            //if denominator = 1, output without denominator
            if((2*a)/divisor == 1)
            {
                //if outsideRoot = 1, output without 1
                if(outsideRoot/divisor == 1)
                {
                    cout << -b/divisor << "+" << "i{" << insideRoot << "}" << ", ";
                    cout << -b/divisor << "-" << "i{" << insideRoot << "}" << endl;
                }
                else
                {
                    cout << "(" << -b/divisor << "+" << outsideRoot/divisor << "i{" << insideRoot << "}" << ")" << ", ";
                    cout << "(" << -b/divisor << "-" << outsideRoot/divisor << "i{" << insideRoot << "}" << ")" << endl;
                }
            }
            else //if denominator is not 1
            {
                //if outsideRoot = 1, remove 1
                if(outsideRoot/divisor == 1)
                {
                    cout << "(" << -b/divisor << "+" << "i{" << insideRoot << "}" << ")" << "/" << (2*a)/divisor << ", ";
                    cout << "(" << -b/divisor << "-" << "i{" << insideRoot << "}" << ")" << "/" << (2*a)/divisor << endl;
                }
                else
                {
                    cout << "(" << -b/divisor << "+" << outsideRoot/divisor << "i{" << insideRoot << "}" << ")" << "/" << (2*a)/divisor << ", ";
                    cout << "(" << -b/divisor << "-" << outsideRoot/divisor << "i{" << insideRoot << "}" << ")" << "/" << (2*a)/divisor << endl;
                }
            }
        }
    }
}

int main()
{
    string quadratic;
    if(myfile.is_open())
    {
        myfile >> quadratic;
    }
    myfile.close();

    char a1 = quadratic[0];
    int a = static_cast<int>(a1) - '0';

    char b1 = quadratic[4];
    int b = static_cast<int>(b1) - '0';
    if(quadratic[3] == '-')
        b = -b;
    else
        b = b;

    char c1 = quadratic[7];
    int c = static_cast<int>(c1) - '0';
    if(quadratic[6] == '-')
        c = -c;
    else
        c = c;

    int discrim = (b)*(b) - 4*(a)*(c);

    simplify(a, b, discrim);

    return 0;
}
