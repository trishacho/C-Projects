#include <iostream>
#include <string>

using namespace std;

int main()
{
    string phoneNumber;
    cout << "Please enter a phone number (with an extension if necessary)." << endl;
    getline(cin, phoneNumber);

    string areaCode = "(919)";
    string extension = "extension ";
    string left = "(";
    string right = ")";

    int length= phoneNumber.size();
    if(length!=13)
    {
       if(length==12)
       {
           phoneNumber = left + phoneNumber;
           phoneNumber.replace(4, 1, right);
           cout << phoneNumber;
       }
       if(length==8)
       {
           phoneNumber = areaCode + phoneNumber;
           cout << phoneNumber;
       }
       if(length==17)
       {
           phoneNumber = left + phoneNumber;
           phoneNumber.replace(4, 1, right);
           phoneNumber.replace(14, 1, extension);
           cout << phoneNumber;
       }
       if(length==18)
       {
           phoneNumber.replace(14, 1, extension);
           cout << phoneNumber;
       }
   }
   else
   {
       if(phoneNumber.compare(9, 1, "x")==0)
       {
           phoneNumber = areaCode + phoneNumber;
           phoneNumber.replace(14, 1, extension);
           cout << phoneNumber;
        }
        else
        {
            cout << phoneNumber;
        }
   }
   return 0;
}
