#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string msg;
    cout << "Please enter a sentence." << endl;
    getline(cin, msg);

    reverse(msg.begin(), msg.end());
    cout << msg << endl;

    if(msg == string(msg.rbegin(), msg.rend()))
    {
        cout << "This is a palindrome." << endl;
    }
    else
    {
        cout << "This is not a palindrome." << endl;
    }

    return 0;
}
