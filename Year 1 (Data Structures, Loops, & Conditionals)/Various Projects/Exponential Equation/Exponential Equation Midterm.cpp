#include<iostream>

 using namespace std;

 int main()
 {
     double x1, y1, x2, y2;
     cout << "Please enter a y-intercept and a point." << endl;
     cin >> x1 >> y1;
     cin >> x2 >> y2;

     double a = y1;
     double b = y2/y1;

     cout << "y=" << a << "(" << b << ")" << "^x" << endl;
     if((b>0)&&(b<1))
     {
         cout << "exponential decay";
     }
     else if(b>0)
     {
         cout << "exponential growth";
     }

     return 0;
 }
