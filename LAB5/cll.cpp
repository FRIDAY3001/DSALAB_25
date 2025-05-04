//use list adt and implement circular linked list

#include <iostream>
using namespace std;

class List
{
    private:

    struct node {
        int data;
        struct node *next;
    }*head = NULL,*tail = head;

    public:

    void insertBeginning(int element)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = element;
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            tail->next = newnode;
        }
    }

    void insertEnd(int element)
    {
        if (head == NULL)
        {
            insertBeginning(element);
        }
        else
        {
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = element;
            tail->next = newnode;
            newnode->next = head;
            tail = newnode;
        }
    }

    void insertPosition(int element, int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty.invalid operation.";
        }
        if (pos == 1)
        {
            insertBeginning(element);
        }
        else
        {
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = element;

            struct node* temp = head;
            for (int i = 1;i < pos-1 && temp->next != head;i++)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }

    }

    void deleteBeginning()
    {
        if (head == NULL)
        {
            cout << "List is empty.";
        }

        if (head->next == head)
        {
            head = NULL;
            tail = NULL;
        }

        else
        {
            struct node* temp = head;
            head = head->next;
            tail->next = head;
            free(temp);
        }
    }

    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty.";
        }

        if (head->next == head)
        {
            deleteBeginning();
        }

        else
        {
            struct node* temp = head;
            while (temp->next->next != head)
            {
                temp = temp->next;
            }
            tail = temp;
            free(temp->next);
            temp->next = head;
        }
    }

    void deletePosition(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty.";
            return;
        }

        if (pos == 1)
        {
            deleteBeginning();
        }

        else
        {
            struct node* temp = head;
            for (int i = 1;i < pos-1 && temp->next != head;i++)
            {
                if (temp == head)
                {
                    cout << "Invalid position";
                    return;
                }
                temp = temp->next;
            }

            if (temp->next == head)
            {
                deleteEnd();
            }
            else
            {
                struct node* node = temp->next;
                temp->next = node->next;
                free(node);
            }
        }
    }

    int search(int key)
    {
        struct node* temp = head;
        int index = 1;
        while (temp->next != head)
        {
            if (temp->data == key)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }

        cout << "Element not present in list. ";
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
            struct node* temp = head;
            while (true)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
                if (temp == head)
                {
                    break;
                }
            }
        }
        cout << " head\n";
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

