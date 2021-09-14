#include<iostream>

using namespace std;

struct student
{
    string name;
    int age;
    double gpa;
};

int main()
{
    student a[5];
//
//    a.name = "XYZ";
//    a.age = 15;
//    a.gpa = 3.8;
//
//    cout << "Enter name, age, and GPA for Student B." << endl;
//    cin >> b.name;
//    cin >> b.age;
//    cin >> b.gpa;
//
//    //Printing the data
//    cout << "Student A's name: " << a.name << endl;
//    cout << "Student B's GPA: " << b.gpa << endl;


    cout << "Enter data of Students 1-5." << endl;
    for(int i=0; i<5; i++)
    {
        cin >> a[i].name;
        cin >> a[i].gpa;
    }

    for (int i=0; i<5; i++)
    {
        if(a[i].gpa > 3)
        {
            cout << a[i].name << " ";
        }
    }
    return 0;
}
