#include<iostream>
#include<string>

using namespace std;

int main()
{
    int i, j, newPosition1, newPosition2;
    string mathExp;
    cout << "Please enter five mathematical expressions." << endl;
    for(i=1; i<=5; i++)
    {
        getline(cin, mathExp);
        int length = mathExp.size();
        int position1 = mathExp.find('(');
        if(position1 >= 0)
        {
            newPosition1 = position1 + 5;
            while(newPosition1<=length+1)
            {
                cout << newPosition1 << " ";
                newPosition1 = newPosition1 + 2;
            }
            cout << endl;
        }
        int position2 = mathExp.find(')');
        if(position2 >= 0)
        {
            newPosition2 = 1;
            while(newPosition2 <= position2-2)
            {
                cout << newPosition2 << " ";
                newPosition2 = newPosition2 + 2;
            }
            cout << endl;
        }
    }
    return 0;
}
