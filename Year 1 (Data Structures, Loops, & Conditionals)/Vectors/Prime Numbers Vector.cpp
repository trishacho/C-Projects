#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    vector <int> primeNumbers;
    for(int i=2; i<=100; i++)
    {
        for(int j=2; j<i; j++)
        {
            if(i%j==0)
            {
                break;
            }
            else if(j==i-1)
            {
                primeNumbers.push_back(i);
            }
        }
    }

    for(int i=0; i<primeNumbers.size(); i++)
    {
        cout << primeNumbers[i] << " ";
    }
    return 0;
}
