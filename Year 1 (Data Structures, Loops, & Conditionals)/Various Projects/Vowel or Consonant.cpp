#include<iostream>

using namespace std;

int main()
{
    char b;
    cout << "Enter an alphabet." << endl;
    cin >> b;

    if(b=='a'||b=='e'||b=='i'||b=='o'||b=='u')
    {
        cout << b << " is a vowel." << endl;
    }
    else if(b=='A'||b=='E'||b=='I'||b=='O'||b=='U')
    {
        cout << b << " is a vowel." << endl;
    }
    else
    {
        cout << b << " is a consonant." << endl;
    }

    return 0;
}
