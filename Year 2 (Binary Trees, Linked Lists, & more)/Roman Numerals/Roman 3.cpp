#include<iostream>
#include<string>

using namespace std;

class Roman
{
	public:
		Roman();
		Roman(string);
        Roman(int);
        void setStr(string);
        string getStr();
        void convertToInt(string);
        void setInt(int);
        int getInt();
        void convertToStr(int);
        void displayProp();
        int operator^(Roman);
	private:
		string romanStr;
		int romanInt;
};

Roman::Roman()
{
    romanStr = "Blank";
    romanInt = 0;
}

Roman::Roman(string romanString)
{
    romanStr = romanString;
    convertToInt(romanString);
}

Roman::Roman(int romanInteger)
{
    romanInt = romanInteger;
    convertToStr(romanInteger);
}

void Roman::setStr(string romanString)
{
    romanStr = romanString;
}

string Roman::getStr()
{
    return romanStr;
}

void Roman::convertToInt(string romanString)
{
    int value = 0;
    string temp = romanString;
    for(int i=0; i<temp.length(); i++)
    {
        if(temp[i]=='I' && temp[i+1]=='V')
        {
            value = value + 4;
            temp[i] = ' ';
            temp[i+1] = ' ';
        }
        else if(temp[i]=='I' && temp[i+1]=='X')
        {
            value = value + 9;
            temp[i] = ' ';
            temp[i+1] = ' ';
        }
        else if(temp[i]=='X' && temp[i+1]=='L')
        {
            value = value + 40;
            temp[i] = ' ';
            temp[i+1] = ' ';
        }
        else if(temp[i]=='X' && temp[i+1]=='C')
        {
            value = value + 90;
            temp[i] = ' ';
            temp[i+1] = ' ';
        }
        else if(temp[i]=='C' && temp[i+1]=='D')
        {
            value = value + 400;
            temp[i] = ' ';
            temp[i+1] = ' ';
        }
        else if(temp[i]=='C' && temp[i+1]=='M')
        {
            value = value + 900;
            temp[i] = ' ';
            temp[i+1] = ' ';
        }

        if(temp[i]=='I')
        {
            value = value + 1;
        }
        else if(temp[i]=='V')
        {
            value = value + 5;
        }
        else if(temp[i]=='X')
        {
            value = value + 10;
        }
        else if(temp[i]=='L')
        {
            value = value + 50;
        }
        else if(temp[i]=='C')
        {
            value = value + 100;
        }
        else if(temp[i]=='D')
        {
            value = value + 500;
        }
        else if(temp[i]=='M')
        {
            value = value + 1000;
        }
    }
    setInt(value);
    setStr(romanString);
}

void Roman::setInt(int romanInteger)
{
    romanInt = romanInteger;
}

int Roman::getInt()
{
    return romanInt;
}

void Roman::convertToStr(int romanInteger)
{
    string temp;
    int number = romanInteger;
    while(number>0)
    {
        if(number>=1000)
        {
            temp = temp + 'M';
            number = number - 1000;
        }
        else if(number>=900)
        {
            temp = temp + "CM";
            number = number - 900;
        }
        else if(number>=500)
        {
            temp = temp + 'D';
            number = number - 500;
        }
        else if(number>=400)
        {
            temp = temp + "CD";
            number = number - 400;
        }
        else if(number>=100)
        {
            temp = temp + 'C';
            number = number - 100;
        }
        else if(number>=90)
        {
            temp = temp + "XC";
            number = number - 90;
        }
        else if(number>=50)
        {
            temp = temp + 'L';
            number = number - 50;
        }
        else if(number>=40)
        {
            temp = temp + "XL";
            number = number - 40;
        }
        else if(number>=10)
        {
            temp = temp + 'X';
            number = number - 10;
        }
        else if(number>=9)
        {
            temp = temp + "IX";
            number = number - 9;
        }
        else if(number>=5)
        {
            temp = temp + 'V';
            number = number - 5;
        }
        else if(number>=4)
        {
            temp = temp + "IV";
            number = number - 4;
        }
        else if(number>=1)
        {
            temp = temp + 'I';
            number = number - 1;
        }
    }
    setInt(romanInteger);
    setStr(temp);
}

void Roman::displayProp()
{
    cout << "Numeral: " << romanStr << endl;
    cout << "Integer: " << romanInt << endl;
}

int Roman::operator^(Roman temp)
{
    if(romanInt == temp.getInt())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void option1()
{
    string romanString;
    cout << "Enter a roman numeral." << endl;
    cin >> romanString;
    Roman temp(romanString);
    temp.convertToInt(romanString);
    temp.displayProp();
}

void option2()
{
    int romanInteger;
    cout << "Enter an integer." << endl;
    cin >> romanInteger;
    Roman temp(romanInteger);
    temp.convertToStr(romanInteger);
    temp.displayProp();
}

void option3()
{
    Roman blank;
    blank.displayProp();

    string romanString;
    cout << "Enter a roman numeral." << endl;
    cin >> romanString;
    Roman temp1(romanString);
    temp1.convertToInt(romanString);
    temp1.displayProp();

    int romanInteger;
    cout << "Enter an integer." << endl;
    cin >> romanInteger;
    Roman temp2(romanInteger);
    temp2.convertToStr(romanInteger);
    temp2.displayProp();

    cout << "Are they equal? " << (temp1^temp2) << endl;
}

int main()
{
//    int option;
//    while(option!=4)
//    {
//        cout << "1) Create a String Only Roman Numeral" << endl;
//        cout << "2) Create an Integer Numeral" << endl;
//        cout << "3) Create a Default Roman Numeral" << endl;
//        cout << "4) Exit" << endl;
//        cin >> option;
//        if(option==1)
//        {
//            option1();
//        }
//        else if(option==2)
//        {
//            option2();
//        }
//        else if(option==3)
//        {
//            option3();
//        }
//    }
//    return 0;

    Roman enloe;
    cout<<"Test 1: "<<enloe.getStr()<<endl;			//Tests Default

    enloe.setStr("Potter");
    cout<<"Test 2: "<<enloe.getStr()<<endl<<endl<<endl;	// Tests setStr

    Roman high("MCXVI");					// Tests basic Roman given string
    cout<< "Test3:"<<endl;
    high.displayProp();
    cout<<endl<<endl;

    Roman school(2772);					// Tests basic Roman given and integer
    cout<<"Test4: "<<endl;
    school.displayProp();
    cout<<endl<<endl;

    cout<<"Test5:"<<endl;					// Tests getInt and Conversion
    cout<<5 + school.getInt()<<endl;
    int value = 5+school.getInt();
    school.setInt(value);
    school.convertToStr(value);
    school.displayProp();
    cout<<endl<<endl;

    cout<<"Test 6:"<<endl;					// Tests special case given integer
    Roman special1(4944);
    special1.displayProp();
    cout<<endl;

    cout<<"Test 7"<<endl;					// Tests special case given string
    Roman special2("CDXLIX");
    special2.displayProp();

    cout<<endl<<endl<<"Test 8";				// Test Operator overlaod
    Roman op1(6);
    Roman op2("VII");
    Roman op3(7);
    cout<<"Check 1:"<<(op1^op2)<<endl;
    cout<<"Check 2:"<<(op2^op3)<<endl;
    cout<<"Check 3:"<<(op1^op3)<<endl<<"DONE";
    return 0;
}
