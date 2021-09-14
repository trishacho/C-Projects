#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector <int> a;
    for(int i=1; i<=10; i++)
    {
        a.push_back(i*10);
    }

    cout << a[2]; //3rd element
    cout << a.at[2]; //3rd element

    cout << a.front(); //First
    cout << a.back(); //Last

    cout << a.size(); //Size vector
    cout << a.capacity(); //Random capacity
    cout << a.maxsize(); //Large size (infinite)

    cout << a.begin(); //index = 0

    a.erase(a.begin(1)); //0 --> Erasing first element
    a.erase(a.begin()+3); //0+3 --> Index =3, erasing 4th element
    a.erase(a.begin(), a.begin(1+5)); //0, 0+5 --> 70, 80, 90, 100

    for(i=0; i<a.size(); i++)
    {
        cout << a[i];
    }

    return 0;
}
