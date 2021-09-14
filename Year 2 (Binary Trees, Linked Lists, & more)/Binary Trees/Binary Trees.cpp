#include<iostream>

using namespace std;
int pleft = 0;
int pright = 0;

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
        void print(bNode*);
        void menu();
        void potter();
};

void Tree::potter() {
	cout<<endl<<endl<<"Potter Test"<<endl;
	cout<<"root: "<<root->getValue()<<endl;
	cout<<"rootsLeft Address: "<<root->getLeft()<<endl;
	cout<<"rootsRight Value: "<<root->getRight()->getValue()<<endl;
	cout<<endl<<endl<<"check left count: "<<pleft<<endl<<"check right count: "<<pright<<endl<<endl;
	cout<<"Insane Random Value: "<<root->getRight()->getLeft()->getLeft()->getLeft()->getLeft()->getValue()<<endl;
	cout<<"Insane address Value: ";
	if (root->getLeft()->getRight() == NULL){
		cout<<"Its just NULL"<<endl;
		root->getLeft()->setRight(new bNode ('#',NULL, NULL));  //<---- May need to change "Bnode"
		pleft = 0;
		pright = 0;
		print(root);
		cout<<endl<<endl<<"check left count: "<<pleft<<endl<<"check right count: "<<pright<<endl<<endl;
		cout<<endl;
	}
	else{
		cout<<"Nothing Happens"<<endl;}
	cout<<endl<<"DONE";
	}

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
            }
            else if(letter > current->getValue() && current->getRight() == NULL)
            {
                current->setRight(temp);
                flag++;
            }
            else if(letter <= current->getValue())
            {
                current = current->getLeft();
            }
            else if(letter > current->getValue())
            {
                current = current->getRight();
            }
        }
    }
}

void Tree::print(bNode *current)
{
    if(root == NULL)
        cout << "Nothing in tree." << endl;
    else
    {
        //cout << current->getValue() << " ";
        if(current->getLeft() != NULL)
        {
            pleft++;
            print(current->getLeft());
        }
        //cout << current->getValue() << " ";
//        if(current->getRight() != NULL)
//        {
//            pright++;
//            print(current->getRight());
//        }
        if(current->getLeft() == NULL)
        {
            cout << "Minimum: " << current->getValue() << endl;
        }
    }
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
            print(root);
            potter();
            cout << endl;
            root = NULL;
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
