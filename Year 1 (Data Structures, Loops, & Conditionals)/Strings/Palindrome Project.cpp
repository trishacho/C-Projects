#include<iostream>
#include<string>

using namespace std;

int main()
{
    string sentence1;
    string sentence2;
    cout << "Please enter a sentence." << endl;
    getline(cin, sentence1);

    sentence2=sentence1;
    int length = sentence1.size();
    int counter;
    counter = length-1;

    int i;
    for(i=0; i<=(length-1); i++)
    {
        sentence2[counter]=sentence1[i];
        counter--;
    }
    cout << sentence2 << endl;

    if(sentence1==sentence2)
    {
        cout << "This is a palindrome." << endl;
    }
    else
    {
        cout << "This is not a palindrome." << endl;
    }

    return 0;
}
