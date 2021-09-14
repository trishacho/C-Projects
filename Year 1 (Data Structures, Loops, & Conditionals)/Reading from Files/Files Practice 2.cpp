#include<iostream>
#include<fstream>

using namespace std;

int main()
{
//    string line;
//    ifstream myfile("trisha.txt");
//    if(myfile.is_open())
//    {
//        while(getline(myfile,line))
//        {
//            cout << line << "\n";
//        }
//        myfile.close();
//    }

    int a[5];
    int i;
    ofstream myfile("Grades.txt");
    if(myfile.is_open())
    {
        cout << "Enter 5 grades." << endl;
        for(i=0; i<5; i++)
        {
            cin >> a[i];
            myfile << a[i] << "\n";
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file.\n";
    }

    return 0;
}
