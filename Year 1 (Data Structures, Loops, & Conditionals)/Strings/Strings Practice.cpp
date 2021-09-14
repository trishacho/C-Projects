#include<iostream>
#include<string>

using namespace std;

int main()
{
    //char name[50] = "Trisha";
    //cout << name;

    //char name[50];
    //cout << "Enter data." << endl;
    //cin.get(name, 50);
    //cout << name;

    //string msg1 = "Farewell";
    //string msg2 = "World";
    //string msg3;
    //int length;

    //int length;
    //string msg1;
    //cout << "Please enter your message." << endl;
    //getline(cin, msg1);
    //length = msg1.size();
    //cout << "The size of your message is: " << length << endl;

    string msg1;
    char bye;
    cout << "Enter a statement you think is true or false." << endl;
    getline (cin, msg1);
    cout << "Is your statement true or false (T or F)?" << endl;
    cin >> bye;
    cout << "The statement " << msg1 << "is " << bye << endl;

    return 0;
}
