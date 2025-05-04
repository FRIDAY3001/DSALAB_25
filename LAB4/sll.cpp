//implement list ADT using singly linked list
#include <iostream>
using namespace std;

class SinglyLinkedList
{
    private:

    struct node 
    {
        int data;
        struct node* next;
    }*head = NULL;

    public:

    SinglyLinkedList() {}

    void insertBeginning(int element)
    {
        struct node* newnode = (struct node* )malloc(sizeof(struct node));

        newnode->data = element;
        newnode->next = head;
        head = newnode;
    }

    void insertEnd(int element)
    {
        if (head == NULL)
        {
            insertBeginning(element);
        }

        else
        {
            struct node* newnode = (struct node* )malloc(sizeof(struct node));
            newnode->data = element;
            struct node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void insertPosition(int element,int position)
    {
        if (position == 1)
        {
            insertBeginning(element);
        }
        else
        {
            struct node* newnode = (struct node* )malloc(sizeof(struct node));
            newnode->data = element;

            struct node* temp = head;

            for (int i = 1;i < position-1;i++)
            {
                if (temp == NULL)
                {
                    cout << "out of range!";
                    return;
                }
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

        else
        {
            struct node* temp = head;
            head = head->next;
            free(temp);
        }
    }

    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty.";
        }

        if (head->next == NULL)
        {
            deleteBeginning();
        }

        else
        {
            struct node* temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            free(temp->next);
            temp->next = NULL;
            
            }
    }

    void deletePosition(int position)
    {
        if (head == NULL)
        {
            cout << "list is empty";
        }
        if (position == 1)
        {
            deleteBeginning();
        }

        else
        {
            struct node* temp = head;
            for (int i = 1; i < position-1;i++)
            {
                if (temp->next == NULL)
                {
                    cout << "out of range!";
                    return;
                }
                temp = temp->next;
            }

            struct node* node = temp->next;
            if (node == NULL) 
            {
                printf("out of range!");
                return;
            }
        
            temp->next = node->next;
            free(node);
        }
    }

    int search(int key)
    {
        struct node* temp = head;
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
        struct node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }



    void reverseLink()
    {
        struct node *prev = NULL, *current = head, *next = NULL;
    
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        printf("List reversed\n");
    }

};

int main()
{
    int option,value,pos;
    SinglyLinkedList list;

    while (option != 10)
    {
        cout << "MENU:\n 1.Insert at the beginning\n 2.Insert at the end\n 3.Insert at a position\n 4.Delete at the beginning\n 5.Delete at the end\n 6.Delete at a position\n 7.Search\n 8.Display\n 9.Reverse Link\n 10.Exit\n";
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
            cout << "element found : " << list.search(value) << "\n";
            break;

            case 8:
            list.display();
            break;


            case 9:
            list.reverseLink();
            break;

            case 10:
            cout << "exiting.";
            break;
        }
    }

    return 0;
}