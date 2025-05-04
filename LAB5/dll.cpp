//implement list adt with doubly linked list
#include <iostream>
using namespace std;

class List
{
    private:

    class Node
    {
        public:
        int data;
        Node* next;
        Node* prev;
    }*head = NULL,*tail = NULL;

    public:

    void insertBeginning(int element)
    {
        Node* newnode = new Node;
        newnode->data = element;
        if (head == NULL)
        {
            newnode->next = head;
            newnode->prev = NULL;
            head = newnode;
            tail = newnode;
        }

        else
        {
            head->prev = newnode;
            newnode->next = head;
            newnode->prev = NULL;
            head = newnode;
        }
    }

    void insertEnd(int element)
    {
        if (head == NULL)
        {
            insertBeginning(element);
        }
        Node* newnode = new Node;
        newnode->data = element;
        
        newnode->prev = tail;
        tail->next = newnode;
        newnode->next = NULL;
        tail = newnode;
    }

    void insertPosition(int element,int pos)
    {
        if (pos == 1)
        {
            insertBeginning(element);
        }

        else
        {
            Node* newnode = new Node;
            newnode->data = element;

            Node* temp = head;
            for (int i = 1;i < pos-1 && temp != NULL;i++)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    void deleteBeginning()
    {
        if (head == NULL)
        {
            cout << "List is empty";
        }

        else
        {
            head = head->next;
            head->prev = NULL;
        }
    }

    void deleteEnd()
    {
        if (head == NULL)
        {
            cout  << "List is empty.";
        }

        if (head == tail)
        {
            deleteBeginning();
        }

        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }

    }

    void deletePosition(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty.";
        }

        if (pos == 1)
        {
            deleteBeginning();
        }

        else
        {
            Node* temp = head;
            for (int i = 1;i < pos-1;i++)
            {
                temp = temp->next;
            }
            Node* node = temp->next;
            temp->next = node->next;
            node->next->prev = temp;
            delete node;
        }
    }

    int search(int key)
    {
        Node* temp = head;
        int index = 1;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }

        cout << "Element not present in list";
        return -1;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty.";
        }

        else
        {
            cout << "display: \n";
            Node* temp1 = head;
            cout  << "NULL -> ";
            while (temp1 != NULL)
            {
                cout << temp1->data << " -> ";
                temp1 = temp1->next;
            }
            cout << "NULL\n";

            cout << "reverse display: \n";
            Node* temp2 = tail;
            cout << "NULL -> ";
            while (temp2 != NULL)
            {
                cout << temp2->data << " -> ";
                temp2 = temp2->prev;
            }
            cout << "NULL\n";
            

        }
    }

};

int main()
{
    int option,value,pos;
    List list;

    while (option != 9)
    {
        cout << "MENU:\n 1.Insert at the beginning\n 2.Insert at the end\n 3.Insert at a position\n 4.Delete at the beginning\n 5.Delete at the end\n 6.Delete at a position\n 7.Search\n 8.Display\n 9.Exit\n";
        cout << "Enter your choice:";
        cin >> option;
        
        switch (option) {

            case 1:
            cout << "Enter an element to insert: ";
            cin >> value;
            list.insertBeginning(value);
            break;

            case 2:
            cout << "Enter an element to insert: ";
            cin >> value;
            list.insertEnd(value);
            break;

            case 3:
            cout << "Enter an element to insert: ";
            cin >> value;
            cout << "Enter a position to insert: ";
            cin >> pos;
            list.insertPosition(value,pos);
            break;

            case 4:
            list.deleteBeginning();
            break;

            case 5:
            list.deleteEnd();
            break;

            case 6:
            cout << "Enter a position to delete: ";
            cin >> pos;
            list.deletePosition(pos);
            break;

            case 7:
            cout << "Enter an element to search: ";
            cin >> value;
            cout << list.search(value) << "\n";
            break;

            case 8:
            list.display();
            break;

            case 9:
            break;
        }
    }

    return 0;
}