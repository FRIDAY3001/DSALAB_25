#include <iostream>
#include "stack.h"
using namespace std;

void checkBalance(char arr[], int n)
{
    stack open;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter bracket: ";
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            open.push(arr[i]);  
        }
        else
        {
            if (open.peek() == '\0')
            {
                cout << "The expression is unbalanced.\n";
                return;
            }

            char ch = open.pop();
            if ((arr[i] == ')' && ch != '(') || (arr[i] == '}' && ch != '{') || (arr[i] == ']' && ch != '['))
            {
                cout << "The expression is unbalanced.\n";
                return;
            }
        }
    }

    if (open.peek() == '\0')
    {
        cout << "The expression is balanced.\n";
    }
    else
    {
        cout << "The expression is unbalanced.\n";
    }
}

int main()
{
    int option,n;
    cout << "Enter length of expression: ";
    cin >> n;

    char bracket[n];

    while (option != 2)
    {
        cout << "MENU:\n1.Check Balance\n2.Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
            case 1:
            checkBalance(bracket,n);
            break;

            case 2:
            cout << "exiting.";
            break;

        }
    }
    return 0;
}