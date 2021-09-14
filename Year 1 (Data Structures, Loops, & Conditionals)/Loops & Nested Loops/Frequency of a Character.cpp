#include<iostream>
#include<string>

using namespace std;

int main()
{
    string a;
    char b;
    int total = 0;
    int i;
    cout << "Please enter a statement." << endl;
    getline(cin, a);
    cout << "Which letter would you like to see the frequency of?" << endl;
    cin >> b;

    for(i=0; i <= a.size(); i++)
    {
        if(a[i]==b)
        {
            total ++;
        }
    }
    cout << "There are " << total << " letters." << endl;

    return 0;
}
