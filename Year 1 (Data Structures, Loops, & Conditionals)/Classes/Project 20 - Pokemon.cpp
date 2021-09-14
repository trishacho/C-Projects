#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class pet
{
    private:
        string name;
        int health;
        int experience;
    public:
        pet();
        void setName(string n);
        int getHealth();
        int getExp();
        void fight();
        void rest();
        void attributes();
        void menu();
};

pet::pet()
{
    health = 100;
    experience = 0;
}

void pet::setName(string n)
{
    name = n;
}

void pet::attributes()
{
    cout << name << endl;
    cout << health << endl;
    cout << experience << endl;
}

int pet::getHealth()
{
    if(health < 91)
    {
        health = health + 10;
    }
    else
    {
        health = health;
    }
    return health;
}

int pet::getExp()
{
    if(experience>=5)
    {
        experience = experience - 5;
    }
    return experience;
}

void pet::rest()
{
    getHealth();
    getExp();
}

void pet::fight()
{
    srand(time(NULL));
    int wld = rand()%3;
    if(wld==0)
    {
        experience = experience + 5;
        health = health - 15;
    }
    if(wld==1)
    {
        experience = experience + 15;
        health = health - 5;
    }
    if(wld==2)
    {
        experience = experience + 10;
        health = health - 10;
    }

    if(health<=0)
    {
        cout << name << " has fainted." << endl;
    }
    if(experience>=100)
    {
        cout << name << " has evolved." << endl;
    }
}

void pet::menu()
{
    int choice = 0;
    cout << "Enter your choice: 0 = Attributes, 1 = Rest, 2 = Fight, 3 = Exit" << endl;
    cin >> choice;
    while(choice!=3)
    {
        if(choice==0)
        {
            attributes();
        }
        if(choice==1)
        {
            rest();
        }
        if(choice==2)
        {
            fight();
        }
        if(choice==3)
        {
            exit(0);
        }
        cout << "Enter your choice: 0, 1, 2, 3" << endl;
        cin >> choice;
    }
}

int main()
{
    string n;
    cout << "Enter the name." << endl;
    cin >> n;

    pet myPoke;
    myPoke.setName(n);

    myPoke.menu();

    return 0;
}
