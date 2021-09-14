#include "E:\\myheader.h"

using namespace std;

const int n = 15;

int main()
{
    int intAry[n];
    char charAry[n];
    double doubAry[n];
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        intAry[i] = rand()%30001;
        cout << intAry[i] << " ";
        charAry[i] = rand()%256;
        doubAry[i] = (rand()%1001)/1000.0;
    }
    BSort(intAry, n);
    BSort(charAry, n);
    BSort(doubAry, n);
    ofstream myfile;
    myfile.open ("TriSort.txt");
    for(int i=0; i<n; i++)
    {
        myfile << intAry[i];
        if((i+1)%10==0)
        {
            myfile << endl;
        }
        else
        {
            myfile << " ";
        }
    }
    myfile << endl;
    for(int i=0; i<n; i++)
    {
        myfile << charAry[i];
        if((i+1)%10==0)
        {
            myfile << endl;
        }
        else
        {
            myfile << " ";
        }
    }
    myfile << endl;
    myfile.setf(ios::showpoint|ios::fixed);
    for(int i=0; i<n; i++)
    {
        myfile << setprecision(3) << doubAry[i];
        if((i+1)%10==0)
        {
            myfile << endl;
        }
        else
        {
            myfile << " ";
        }
    }
    myfile.close();
    return 0;
}
