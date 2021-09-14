#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main()
{
    vector <char> sVec;
    string inString;
    ifstream myfile;
    char vType = ' ';

    myfile.open("testData.txt", ifstream::in);

    if(!myfile)
    {
        cout << "Error: cannot open file named testData.txt." << endl;
    }
    else
    {
        getline(myfile, inString);

        while(myfile)
        {
            cout << endl << inString << endl;
            int sLength = inString.length();
            vType = inString[0];

            for(int i=1; i<sLength; i++)
            {
                if(inString[i]=='X')
                {
                    if(vType=='S')
                        sVec.pop_back();
                    if(vType=='Q')
                        sVec.erase(sVec.begin());
                }
                else
                    sVec.push_back(inString[i]);
            }
            int vSize = sVec.size();
            for(int i=0; i<vSize; i++)
                cout << sVec[i];

            cout << endl;

            getline(myfile, inString);
            sVec.erase(sVec.begin(), sVec.begin()+vSize);
        }
    }
    return 0;
}
