//implement stack adt using singly linked list
#include <iostream>
using namespace std;

class stack 
{
    private:

    class node
    {
        public:        
        int data;
        node* next;
    }*top = NULL;

    public:

    void push(int element)
    {
        node* newnode = new node;
        newnode->data = element;
        newnode->next = top;
        top = newnode;

    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty.\n";
            return -1;
        }
        else if (top->next == NULL)
        {
            node* temp = top;
            int value = top->data;
            top = NULL;
            delete temp;
            return value;
        }
        else
        {
            int value = top->data;
            node* temp = top;
            top = top->next;
            delete temp;
            return value;
            }
    }

    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty.\n";
        }
        else 
        {
            cout << top->data << "\n";
        }
    }
};

int main()
{
    int option,value;
    stack s;

    while (option < 4)
    {
        cout << "MENU:\n1.Push\n2.Pop\n3.Peek\n4.Exit\n";
        cout << "Enter your choice: ";
        cin >> option;
        switch (option)
        {
            case 1:
            cout << "Enter value to push to stack: ";
            cin >> value;
            s.push(value);
            break;

            case 2:
            cout << "Popped element: ";
            cout << s.pop() << "\n";
            break;

            case 3:
            cout << "Top most element of stack: ";
            s.peek();
            break;

            case 4:
            cout << "Exiting";
            break;
        }
    }
    return 0;
}