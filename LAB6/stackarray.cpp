//implement stack adt using array of size 5
#include<iostream>
using namespace std;

class stack 
{
    private:

    int top;
    int arr[5];

    public:

    stack() {
        top = -1;
    }

    void push(int element)
    {
        if (top == -1)
        {
            arr[0] = element;
            top+=1;   
        }

        else if (top == 4)
        {
            cout << "Stack is full.";
        }
        else
        {
            arr[top+1] = element;
            top+=1;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << arr[top] << "\n";
            top-=1;
        }
    }
    
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << arr[top];
            cout << "\n";
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
            s.pop();
            break;

            case 3:
            cout << "Top most element of stack: ";
            s.peek();
            break;

            case 4:
            cout << "Exiting program.";
            break;
        }
    }
    return 0;
}