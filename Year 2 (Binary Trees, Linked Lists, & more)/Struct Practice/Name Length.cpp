#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct person
{
    string name;
    int nameLen;
    int numVowels;
};

const int n = 5;

int numberOfVowels(string name)
{
    int vowels = 0;
    for(int i=0; i<name.length(); i++)
    {
        if(name[i] == 'a'||name[i] == 'e'||name[i] == 'i'||name[i] == 'o'||name[i] == 'u')
        {
            vowels++;
        }
        else
        {
            vowels = vowels;
        }
    }
    return vowels;
}

void input(person group[])
{
   cout << "Enter names." << endl;
   for(int i=0; i<n; i++)
   {
       cin >> group[i].name;
       group[i].nameLen = group[i].name.length();
       group[i].numVowels = numberOfVowels(group[i].name);
   }
}

void swap(person &a, person &b)
{
    person temp;
    temp = a;
    a = b;
    b = temp;
}

void sortLength(person group[])
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(group[i].nameLen < group[j].nameLen)
            {
                swap(group[i], group[j]);
            }
        }
    }
}

void sortVowels(person group[])
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(group[i].numVowels < group[j].numVowels)
            {
                swap(group[i], group[j]);
                if(group[i].numVowels == group[j].numVowels)
                {
                    if(group[i].nameLen < group[j].nameLen)
                    {
                        swap(group[i], group[j]);
                    }
                }
            }
        }
    }
}

void outputDisplay(person group[])
{
    cout << endl;
    cout << setw(13) << left << "Name";
    cout << setw(13) << left << "Length";
    cout << setw(13) << left << "Vowels" << endl;
    for(int i=0; i<n; i++)
    {
        cout << setw(13) << left << group[i].name;
        cout << setw(13) << left << group[i].nameLen;
        cout << setw(13) << left << group[i].numVowels << endl;
    }
}

int main()
{
    person members[n];

    input(members);
    //sortLength(members);
    //outputDisplay(members);
    sortVowels(members);
    outputDisplay(members);

    return 0;
}
