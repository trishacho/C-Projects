//Trisha Choudhary
//Pd 4(A)
#include<iostream>
using namespace std;

class ListNode
{
    private:
        int data;
        ListNode *next;
    public:
        ListNode(int d, ListNode *n)
        {
            data = d;
            next = n;
        }
        int getData()
        {
            return data;
        }
        void setData(int newData)
        {
            data = newData;
        }
        ListNode* getNext()
        {
            return next;
        }
        void setNext(ListNode *n)
        {
            next = n;
        }
};

class List
{
    private:
        ListNode *first;
        ListNode *current;
    public:
        List()
        {
            first = NULL;
        }
        void print();
        void menu();
        void insert(int);
        void Delete();
};

void List::insert(int x)
{
    ListNode *temp = new ListNode(x, NULL);
    ListNode *current = first;
    if(current == NULL)
    {
        first = temp;
    }
    else
    {
        if(x < first->getData())
        {
            temp->setNext(first);
            first = temp;
        }
        else
        {
            int flag = 0;
            while(current != NULL && flag == 0)
            {
                if(x >= current->getData() && (current->getNext() == NULL))
                {
                    current->setNext(temp);
                    flag++;
                }
                else if(x >= current->getData() && x <= current->getNext()->getData())
                {
                    temp->setNext(current->getNext());
                    current->setNext(temp);
                    flag++;
                }
                else
                {
                    current = current->getNext();
                }
            }
        }
    }
}

void List::Delete()
{
    int deleteNumber;
    cout << "Enter number to delete." << endl;
    cin >> deleteNumber;
    ListNode *current = first;
    if(current == NULL)
    {
        cout << "Nothing to delete." << endl;
    }
    else
    {
        if(deleteNumber == first->getData())
        {
            first = first->getNext();
        }
        else
        {
            int flag = 0;
            while(current->getNext() != NULL && flag == 0)
            {
                if(current->getNext()->getData() == deleteNumber)
                {
                    if(current->getNext() != NULL)
                    {
                        current->setNext(current->getNext()->getNext());
                    }
                    flag++;
                }
                if(current->getNext() != NULL) current = current->getNext();
            }
            if(flag == 0) cout << "That number is not on the list. Try again." << endl;
        }
    }
}

void List::print()
{
    ListNode *current = first;
    if(first==NULL)
    {
        cout << "Nothing in list.";
    }
    else
    {
        while(current!=NULL)
        {
            cout << current->getData() << " ";
            current = current->getNext();
        }
    }
    cout << endl;
}

void List::menu()
{
    int option;
    int value;
    cout << "Enter 1 (Insert), 2 (Print), 3 (Exit), or 4 (Delete)." << endl;
    cin >> option;
    while(option!=5)
    {
        if(option == 1)
        {
            cout << "Enter a value." << endl;
            cin >> value;
            insert(value);
            cout << "Enter 1 (Insert), 2 (Print), 3 (Exit), or 4 (Delete)." << endl;
            cin >> option;
        }
        if(option == 2)
        {
            print();
            cout << endl;
            cout << "Enter 1 (Insert), 2 (Print), 3 (Exit), or 4 (Delete)." << endl;
            cin >> option;
        }
        if(option == 3)
        {
            option = 5;
        }
        if(option == 4)
        {
            Delete();
            cout << "Enter 1 (Insert), 2 (Print), 3 (Exit), or 4 (Delete)." << endl;
            cin >> option;
        }
    }
}

int main()
{
    List l;
    l.menu();
    return 0;
}
