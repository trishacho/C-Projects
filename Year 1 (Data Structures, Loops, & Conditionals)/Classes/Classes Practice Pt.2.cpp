#include<iostream>
using namespace std;

class time
{
    public: //these items are available to use as functions
        time(); //default constructor
        void setTime (int, int, int, int); //method to set the time
        int military(); //method to convert standard to military (24 hr) time
        int greenwich(); //greenwich standard time
        int normalhour();
        void print(); //displays the time
    private:
        int hour; //private variables are only accessible within the class
        int min; //by using the methods to set or get the data
        int sec;
        int ampm; //am = 0, pm = 1
};

time::time() //default constructor sets variables to a default time
{
    hour = 12; //think of your microwave clock when the power is lost
    min = sec = ampm = 0;
}

void time::setTime(int h, int m, int s, int a) //setter sets the time with the given inputs
{
    hour = h;
    min = m;
    sec = s;
    ampm = a;
}

int time::normalhour()
{
    if(hour >= 24)
    {
        hour - 12;
    }
    return hour;
}

int time::military() //changes hour to military time
{
    if(ampm==1)
    {
        hour += 12;
    }
    if(hour > 24)
    {
        hour = hour-12;
    }
    return hour;
}

int time::greenwich()
{
    hour += 7;
    if(hour > 24)
    {
        hour = hour-12;
    }
    if(hour > 13)
    {
        hour = hour-12;
    }
    return hour;
}

void time::print() //display time to the console
{

    cout << "The normal time is: ";
    hour = normalhour();
    cout << hour << ":" << min << ":" << sec;
    cout << endl;
    cout << "The time in military time is: ";
    hour = military();
    cout << hour << ":" << min << ":" << sec;
    cout << endl;
    cout << "The time in GMT is: ";
    hour = greenwich();
    cout << hour << ":" << min << ":" << sec;
}

int main()
{
    time d;
    int h1, m1, s1, a1;
    cout << "Hour: ";
    cin >> h1;
    cout << "Minute: ";
    cin >> m1;
    cout << "Second: ";
    cin >> s1;
    cout << "Enter 0 for am, 1 for pm: ";
    cin >> a1;
    d.setTime(h1, m1, s1, a1);
    d.print();

    return 0;
}
