#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector <string> sortVector;
    string vec;

    cout << "Enter input." << endl;
    for(int i=0; i<3; i++)
    {
        getline(cin, vec);
        sortVector.push_back(vec);
    }

    for(int i=0; i<sortVector.size(); i++)
    {
        for(int j=i+1; j<sortVector.size(); j++)
        {
            if(sortVector[i]>sortVector[j])
            {
                vec = sortVector[i];
                sortVector[i]=sortVector[j];
                sortVector[j]=vec;
            }
        }
    }

    cout << "OUTPUT:" << endl;
    for(int i=0; i<sortVector.size(); i++)
    {
        cout << sortVector[i] << endl;
    }

    return 0;
}
