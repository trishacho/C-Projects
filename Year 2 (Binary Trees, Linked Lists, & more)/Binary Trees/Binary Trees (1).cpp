#include<iostream>

using namespace std;

class bNode
{
    private:
        char value;
        bNode *right;
        bNode *left;
    public:
        bNode(char v, bNode *r, bNode*l)
        {
            value = v;
            right = r;
            left = l;
        }
        char getValue()
        {
            return value;
        }
        void setValue(char newValue)
        {
            value = newValue;
        }
        bNode* getRight()
        {
            return right;
        }
        bNode* getLeft()
        {
            return left;
        }
        void setRight(bNode *r)
        {
            right = r;
        }
        void setLeft(bNode *l)
        {
            left = l;
        }
};

class Tree
{
    private:
        bNode *root;
    public:
        Tree()
        {
            root = NULL;
        }
        void createTree(char);
        void print(bNode*); //needs parameter bNode
        void menu();
};

void Tree::createTree(char letter)
{
    bNode *current = root;
    bNode *temp = new bNode(letter, NULL, NULL);
    int flag = 0;
    if(root == NULL)
    {
        root = new bNode(letter, NULL, NULL);
    }
    else
    {
        while(current != NULL && flag == 0)
        {
            if(letter <= current->getValue() && current->getLeft() == NULL)
            {
                current->setLeft(temp);
                flag++;
                cout << "hi 1" << endl;
            }
            else
            {
                current->setRight(temp);
                flag++;
                cout << "hi 2" << endl;
            }
            if(letter <= current->getValue())
            {
                current = current->getLeft();
                cout << "hi 3" << endl;
            }
            else
            {
                current = current->getRight();
                cout << "hi 4" << endl;
            }
        }
    }
}

void Tree::print(bNode *current) //needs parameter bNode
{
    if(current->getLeft() != NULL)
        print(current->getLeft());
    cout << current->getValue() << " ";
    if(current->getRight() != NULL)
        print(current->getRight());
}

void Tree::menu()
{
    int option;
    string word;
    cout << "Enter 1 (Insert), 2 (Print), or 3 (Exit)." << endl;
    cin >> option;
    while(option!=4)
    {
        if(option == 1)
        {
            cout << "Enter word." << endl;
            cin >> word;
            for(int i=0; i<word.size(); i++)
            {
                createTree(word[i]);
            }
            cout << "Enter 1 (Insert), 2 (Print), or 3 (Exit)." << endl;
            cin >> option;
        }
        if(option == 2)
        {
            print(root); //needs parameter
            cout << endl;
            cout << "Enter 1 (Insert), 2 (Print), or 3 (Exit)." << endl;
            cin >> option;
        }
        if(option == 3)
        {
            option = 4;
        }
    }
}

int main()
{
    Tree t;
    t.menu();
    return 0;
}
