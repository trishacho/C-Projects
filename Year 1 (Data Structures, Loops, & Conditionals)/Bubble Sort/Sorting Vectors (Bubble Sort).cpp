#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector <char> sortVector;
    string vec;
    int temp;

    cout << "Enter input." << endl;
    getline(cin, vec);
    for(int i=0; i<vec.size(); i++)
    {
        sortVector.push_back(vec[i]);
    }

    for(int i=0; i<sortVector.size(); i++)
    {
        for(int j=0; j<sortVector.size()-1; j++)
        {
            if(sortVector[j]>sortVector[j+1])
            {
                temp = sortVector[j];
                sortVector[j]=sortVector[j+1];
                sortVector[j+1]=temp;
            }
        }
    }

    for(int i=0; i<sortVector.size(); i++)
    {
        cout << sortVector[i] << endl;
    }

    return 0;
}
