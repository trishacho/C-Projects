#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream myfile;
    myfile.open("testData.txt");
    if(myfile)
    {
        myfile << "SENLOEXXHIGHX \n";
        myfile << "QFIXRSTXINFLIXGHT \n";
        myfile << "SHELLOWXORLDX \n";
        myfile.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
    return 0;
}
