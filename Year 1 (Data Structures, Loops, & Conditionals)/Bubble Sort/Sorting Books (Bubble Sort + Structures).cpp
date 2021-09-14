#include<iostream>
#include<string>

using namespace std;

struct book
{
    string title;
    string genre;
    int serNumber;
};

int main()
{
    book a[10];
    string n;
    cout << "Enter the data of the books." << endl;
    for(int i=0; i<3; i++)
    {
        cin >> a[i].title;
        cin >> a[i].genre;
        cin >> a[i].serNumber;
    }
    cout << "What would you like to sort?" << endl;
    cin >> n;

    string vec;
    int temp;

    if(n=="Genre")
    {
        for(int i=0; i<3; i++)
        {
            for(int j=i+1; j<3; j++)
            {
                if(a[i].genre>a[j].genre)
                {
                    vec = a[i].genre;
                    a[i].genre = a[j].genre;
                    a[j].genre = vec;
                }
            }
        }
        for(int i=0; i<3; i++)
        {
            cout << a[i].genre << endl;
        }
    }
    else if(n=="Title")
    {
        for(int i=0; i<3; i++)
        {
            for(int j=i+1; j<3; j++)
            {
                if(a[i].title>a[j].title)
                {
                    vec = a[i].title;
                    a[i].title = a[j].title;
                    a[j].title = vec;
                }
            }
        }
        for(int i=0; i<3; i++)
        {
            cout << a[i].title << endl;
        }
    }
    else if(n=="SerialNumber")
    {
       for(int i=0; i<3; i++)
       {
           for(int j=0; j<3-1; j++)
           {
               if(a[j].serNumber>a[j+1].serNumber)
               {
                   temp = a[j].serNumber;
                   a[j].serNumber = a[j+1].serNumber;
                   a[j+1].serNumber = temp;
               }
           }
       }
       for (int i=0; i<3; i++)
       {
           cout << a[i].serNumber << endl;
       }
    }
    return 0;
}
