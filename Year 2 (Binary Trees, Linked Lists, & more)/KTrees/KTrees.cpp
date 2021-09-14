#include<iostream>

using namespace std;

class KNode
{
    private:
        char priority;
        int coorX;
        int coorY;
        KNode *right;
        KNode *left;
    public:
        KNode(char p, int x, int y, KNode *r, KNode*l)
        {
            priority = p;
            coorX = x;
            coorY = y;
            right = r;
            left = l;
        }
        char getPriority()
        {
            return priority;
        }
        void setPriority(char newPriority)
        {
            priority = newPriority;
        }
        int getX()
        {
            return coorX;
        }
        void setX(int newX)
        {
            coorX = newX;
        }
        int getY()
        {
            return coorY;
        }
        void setY(int newY)
        {
            coorY = newY;
        }
        KNode* getRight()
        {
            return right;
        }
        KNode* getLeft()
        {
            return left;
        }
        void setRight(KNode *r)
        {
            right = r;
        }
        void setLeft(KNode *l)
        {
            left = l;
        }
};

class KTree
{
    private:
        KNode *root;
    public:
        KTree()
        {
            root = NULL;
        }
        void insert(int, int, KNode*);
        void printNormal(KNode*);
        void printX(KNode*);
        void printAddOn(KNode*);
        void menu();
};

void KTree::insert(int x, int y, KNode *current)
{
    KNode *temp;
    char prior;
    if(root == NULL)
    {
        cout << "Enter priority X or Y: ";
        cin >> prior;
        root = new KNode(prior, x, y, NULL, NULL);
        current = root;
    }
    else
    {
        if(current->getPriority() == 'X')
        {
            if(x <= current->getX() && current->getLeft() == NULL)
            {
                temp = new KNode('Y', x, y, NULL, NULL);
                current->setLeft(temp);
            }
            else if(x > current->getX() && current->getRight() == NULL)
            {
                temp = new KNode('Y', x, y, NULL, NULL);
                current->setRight(temp);
            }
            else
            {
                if(x <= current->getX())
                {
                    insert(x, y, current->getLeft());
                }
                else if(x > current->getX())
                {
                    insert(x, y, current->getRight());
                }
            }
        }
        else
        {
            if(y <= current->getY() && current->getLeft() == NULL)
            {
                temp = new KNode('X', x, y, NULL, NULL);
                current->setLeft(temp);
            }
            else if(y > current->getY() && current->getRight() == NULL)
            {
                temp = new KNode('X', x, y, NULL, NULL);
                current->setRight(temp);
            }
            else
            {
                if(y <= current->getY())
                {
                    insert(x, y, current->getLeft());
                }
                else if(y > current->getY())
                {
                    insert(x, y, current->getRight());
                }
            }
        }
    }
}

void KTree::printNormal(KNode *current)
{
    if(root == NULL)
        cout << "Nothing in tree." << endl;
    else
    {
        if(current->getLeft() != NULL)
        {
            printNormal(current->getLeft());
        }
        cout << "(" << current->getX() << "," << current->getY() << ")" << " ";
        if(current->getRight() != NULL)
        {
            printNormal(current->getRight());
        }
    }
}

void KTree::printX(KNode *current)
{
    if(root == NULL)
        cout << "Nothing in tree." << endl;
    else
    {
        if(current->getLeft() != NULL)
        {
            printX(current->getLeft());
        }
        if(current->getPriority() == 'X')
        {
            cout << "(" << current->getX() << "," << current->getY() << ")" << " ";
        }
        if(current->getRight() != NULL)
        {
            printX(current->getRight());
        }
    }
}

void KTree::printAddOn(KNode *current)
{
    if(root == NULL)
        cout << "Nothing in tree." << endl;
    else
    {
        if(current->getLeft() != NULL)
        {
            printAddOn(current->getLeft());
        }
        if(current->getLeft() == NULL && current->getRight() != NULL || current->getRight() == NULL && current->getLeft() != NULL)
        {
            cout << "(" << current->getX() << "," << current->getY() << ")" << " ";
        }
        if(current->getRight() != NULL)
        {
            printAddOn(current->getRight());
        }
    }
}

void KTree::menu()
{
    int option;
    int x, y;
    cout << "Enter 1 (Insert), 2 (Print), or 3 (Exit)." << endl;
    cin >> option;
    while(option!=4)
    {
        if(option == 1)
        {
            cout << "Enter x and y coordinates: ";
            cin >> x >> y;
            insert(x, y, root);
            cout << "Enter 1 (Insert), 2 (Print), or 3 (Exit)." << endl;
            cin >> option;
        }
        if(option == 2)
        {
            cout << "Normal: ";
            printNormal(root);
            cout << endl;
            cout << "X-Coordinate Priority: ";
            printX(root);
            cout << endl;
            cout << "One Child: ";
            printAddOn(root);
            cout << endl;
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
    KTree k;
    k.menu();
    return 0;
}
