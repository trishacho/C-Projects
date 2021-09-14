#include<iostream>

using namespace std;

struct student
{
    string name;
    int grade;
};

int main()
{
    student a[5];
    double avg;
    double total = 0;

    cout << "Enter data of Students 1-5." << endl;
    for(int i=0; i<5; i++)
    {
        cin >> a[i].name;
        cin >> a[i].grade;
    }

    for(int i=0; i<5; i++)
    {
        total = a[i].grade + total;
    }

    avg = total/5.0;

    for(int i=0; i<5; i++)
    {
        if(a[i].grade >= avg)
        {
            cout << a[i].name << " ";
        }
    }
    return 0;
}
