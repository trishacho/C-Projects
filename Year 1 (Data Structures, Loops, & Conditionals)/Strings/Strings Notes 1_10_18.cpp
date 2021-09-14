#include<iostream>
#include<string>

using namespace std;

int main()
{
    //declare and initialize two character arrays
    char message1[15] = {'H','e','l','l','o','\0'};
    char message2[15] = {" World"};
    cout << message1 << message2 << endl;

    //declare and initialize strings
    string msg1 = "Farewell";
    string msg2 = " World!";
    string msg3;

    int length;

    //copy string 1 to string 3
    msg3=msg1;
    cout << "msg 3 is: " << msg3 << endl;

    //concentrate two strings
    msg3 = msg1 + msg2;
    cout << "msg3 = msg1 + msg2 is: " << msg3 << endl;

    //find the length of message 2
    length = msg3.size();
    cout << "msg 3 size is: " << length << endl;

    //using the substring method (remember the index starts at zero)
    string msg4 = msg1.substr(4,7);
    cout << "msg4 is: " << msg4 << endl;

    //find the position of the space in message 3
    int position = msg3.find(' ');
    cout << "The space in msg3 is at location " << position << endl;

    //replace a part of a string (start at position 9 for 5 places and use message 5)
    string msg5 = " Moon";
    msg3.replace(9,5,msg5);
    cout << "msg 3 is now " << msg3 << endl;

    //comparing two strings to see if they are equal
    //returns a 0 if they are the same
    //returns <0 if first character is lower in value
    //returns >0 if first character is greater in value
    if(msg1.compare(msg3)!=0)
        cout << "msg1 is not the same as msg 3" << endl;

    if (msg3.compare(0,7,msg1,0,7)==0)
        cout << "msg1 and msg3 first words are the same" << endl;

    return 0;
}
