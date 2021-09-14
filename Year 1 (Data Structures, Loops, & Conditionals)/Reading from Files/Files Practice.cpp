#include<iostream>
#include<fstream>

using namespace std;

int main()
//{
//    ofstream myfile;
//    myfile.open("example.txt");
//    myfile << "Write to a file..." << endl;
//    myfile.close();
//
//    return 0;
//}

{
    ofstream myfile("trisha.txt");
    if(myfile.is_open())
    {
        myfile << "My name is Trisha. \n";
        myfile << "My favorite color is turquoise.\n";
        myfile << "I like to eat Chipotle burritos.\n";
        myfile << "My birthday is in 2 days!\n";
        myfile << "Super Junior.\n";
        myfile.close();
    }
    else
    {
        cout << "Unable to open file.\n";
    }

    return 0;
}



