#include<iostream>
using namespace std;

//STRUCTURES
struct student
{
    string name;
};

void printname(string B)
{
    cout << B;
}

int main()
{
    student a;
    a.name = "XYZ";
    printname(a.name);
    return 0;
}

//CLASSES
class student
{
    public:
        string name;
        void printname()
        {
            cout << name;
        }
};

int main()
{
    student a;
    a.name = "XYZ";
    a.printname();
    return 0;
}
