#include<iostream>
#include<stdlib.h>
#include<string>
#include <iomanip>

using namespace std;

int pos = 0;

class ENode
{
    private:
        char data;
        double value;
        ENode *right;
        ENode *left;
    public:
        ENode(char d, ENode *r, ENode *l)
        {
            data = d;
            if(data != '+' || data != '-' || data != '*' || data != '/' || data != 'd' || data != 'f')
            {
                value = double(d - 48);
            }
            right = r;
            left = l;
        }
        char getData()
        {
            return data;
        }
        void setData(char newData)
        {
            data = newData;
        }
        double getValue()
        {
            return value;
        }
        void setValue(double newValue)
        {
            value = newValue;
        }
        ENode *getRight()
        {
            return right;
        }
        void setRight(ENode *r)
        {
            right = r;
        }
        ENode *getLeft()
        {
            return left;
        }
        void setLeft(ENode *l)
        {
            left = l;
        }
};

class ETree
{
    private:
        ENode *root;
    public:
        ETree()
        {
            root = NULL;
        }
        void create(string&, ENode*);
        void print(ENode*);
        void menu();
        void Evaluate(ENode*);
        void PrintAnswer(ENode*);
};

void ETree::create(string& input, ENode *current)
{
    if(root == NULL)
    {
        root = new ENode(input[pos], NULL, NULL);
        current = root;
    }

    ENode *temp1 = new ENode(input[pos+1], NULL, NULL);
    current->setLeft(temp1);
    pos++;
    if(current->getLeft()->getData() == '+' || current->getLeft()->getData() == '-' || current->getLeft()->getData() == '*' ||
       current->getLeft()->getData() == '/' || current->getLeft()->getData() == 'd' || current->getLeft()->getData() == 'f')
    {
        create (input, current->getLeft());
    }

    ENode *temp2 = new ENode(input[pos+1], NULL, NULL);
    current->setRight(temp2);
    pos++;
    if(current->getRight()->getData() == '+' || current->getRight()->getData() == '-' || current->getRight()->getData() == '*' ||
        current->getRight()->getData() == '/' || current->getRight()->getData() == 'd' || current->getRight()->getData() == 'f')
    {
        create (input, current->getRight ());
    }
}

void ETree::Evaluate(ENode *current)
{
    if(current->getData() == '+' || current->getData() == '-' || current->getData() == '*' || current->getData() == '/' || current->getData() == 'd')
    {
        if(current->getLeft()->getData() == '+' || current->getLeft()->getData() == '-' || current->getLeft()->getData() == '*' ||
           current->getLeft()->getData() == '/' || current->getLeft()->getData() == 'd' || current->getLeft()->getData() == 'f')
        {
            Evaluate (current->getLeft());
        }
        if(current->getRight()->getData() == '+' || current->getRight()->getData() == '-' || current->getRight()->getData() == '*' ||
           current->getRight()->getData() == '/' || current->getRight()->getData() == 'd' || current->getRight()->getData() == 'f')
        {
            Evaluate (current->getRight());
        }

        double total = 0;
        if(current->getData() == '+')
        {
            total = current->getLeft()->getValue() + current->getRight()->getValue();
            current->setValue(total);
        }
        else if(current->getData() == '-')
        {
            total = current->getLeft()->getValue() - current->getRight()->getValue();
            current->setValue(total);
        }
        else if(current->getData() == '*')
        {
            total = current->getLeft()->getValue()*current->getRight()->getValue();
            current->setValue(total);
        }
        else if(current->getData() == '/')
        {
            total = current->getLeft()->getValue()/current->getRight()->getValue();
            current->setValue(total);
        }
        else if(current->getData() == 'd')
        {
            if(current->getLeft()->getValue() > current->getRight()->getValue())
            {
                total = current->getLeft()->getValue() + 1;
                current->setValue(total);
            }
            if(current->getRight()->getValue() > current->getLeft()->getValue())
            {
                total = current->getRight()->getValue() + 1;
                current->setValue(total);
            }
        }
        else if(current->getData() == 'f')
        {
            int factorial = current->getLeft()->getValue();
            int temp;
            for(int i=factorial; i>0; i-=2)
            {
                temp = i*(i-1);
                total = total + temp;
            }
            current->setValue(total);
        }
    }
}

void ETree::print(ENode *current)
{
    if (root == NULL)
        cout << "Nothing in tree." << endl;
    else
    {
        if(current->getLeft() != NULL)
        {
            print(current->getLeft());
        }
        cout << current->getData();
        if(current->getRight() != NULL)
        {
            print(current->getRight());
        }
    }
}

void ETree::PrintAnswer(ENode *current)
{
    if(root == NULL)
    {
        cout << "No Tree = No Answer." << endl;
    }
    else
    {
        Evaluate(root);
        cout << fixed << showpoint;
        cout << "The answer is: " << setprecision(3) << root->getValue() << endl;
        cout << "Done.";
    }
}

void ETree::menu()
{
    int option;
    string expression;
    cout << "Enter 1 (Create), 2 (Print), 3 (Evaluate), or 4 (Exit)." << endl;
    cin >> option;
    while(option != 5)
    {
        if(option == 1)
        {
            //reset
            root = NULL;
            pos = 0;

            cout << "Enter expression: ";
            cin >> expression;
            create(expression, root);
            cout << "Enter 1 (Create), 2 (Print), 3 (Evaluate), or 4 (Exit)." << endl;
            cin >> option;
        }
        if(option == 2)
        {
            print(root);
            cout << endl;
            cout << "Enter 1 (Create), 2 (Print), 3 (Evaluate), or 4 (Exit)." << endl;
            cin >> option;
        }
        if(option == 3)
        {
            PrintAnswer(root);
            root = NULL;
            cout << endl;
            cout << endl;
            cout << "Enter 1 (Create), 2 (Print), 3 (Evaluate), or 4 (Exit)." << endl;
            cin >> option;
        }
        if (option == 4)
        {
            option = 5;
        }
    }
}

int main ()
{
    ETree t;
    t.menu();
    return 0;
}
