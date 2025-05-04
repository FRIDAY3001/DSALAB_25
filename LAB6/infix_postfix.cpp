//program to convert infix to postfix expression
#include <iostream>
#include "stack.h"
using namespace std;

void getInfix(char arr[],int n)
{
    if (n == 1 or n%2 == 0)
    {
        cout << "Not valid, try again!";
    }

    else
    {
        for (int i = 0; i < n;i++)
        {
            cout << "Enter term of expression:";
            cin >> arr[i];
        }
    }
}

void convertInfix(char arr[], int n)
{
    stack oper;
    char postfix[n]; 
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '%')
        {
            while (oper.peek() != '\0')  
            {
                if (oper.peek() == '*' || oper.peek() == '/' || oper.peek() == '%')
                {
                    if (arr[i] == '+' || arr[i] == '-')  
                    {
                        postfix[j++] = oper.pop();  
                    }
                    else  
                    {
                        postfix[j++] = oper.pop();
                        oper.push(arr[i]);
                        break;
                    }
                }

                if (oper.peek() == '+' || oper.peek() == '-')
                {
                    if (arr[i] == '+' || arr[i] == '-')  
                    {
                        postfix[j++] = oper.pop();
                    }
                    else  
                    {
                        break;
                    }
                }
            }
            oper.push(arr[i]);  
        }
        else  
        {
            postfix[j++] = arr[i]; 
        }
    }

    while (oper.peek() != '\0')
    {
        postfix[j++] = oper.pop();  
    }

  
    for (int i = 0; i < n; i++)
    {
        arr[i] = postfix[i];
    }

    cout << "Postfix: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


void evalPostfix(char arr[], int n) {
    stack operand;

    for (int i = 0; i < n; i++) {
        char token = arr[i];

        if (isdigit(token)) {
            operand.push(token); 
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '%') {
            int op2 = operand.pop() - '0';
            int op1 = operand.pop() - '0';
            int result = 0;

            switch (token) {
                case '+': 
                result = op1 + op2; 
                break;
                case '-': 
                result = op1 - op2; 
                break;
                case '*': 
                result = op1 * op2; 
                break;
                case '/': 
                    if (op2 == 0) 
                    {
                        cout << "Division by zero error.\n";
                        return;
                    }
                    result = op1 / op2;
                    break;
                case '%': 
                    if (op2 == 0) 
                    {
                        cout << "zero error.\n";
                        return;
                    }
                    result = op1 % op2; 
                    break;
            }

            operand.push(result + '0');
        }
    }

    cout << "Evaluated expression: " << (operand.pop() - '0') << endl;
}

int main()
{
    int option,n;
    cout << "Enter size of infix expression:";
    cin >> n;
    char infix[n];

    while (option != 4)
    {
        cout << "MENU:\n1.Get Infix\n2.Convert Infix\n3.Evaluate Postfix\n4.Exit\n";
        cout << "Enter your choice: ";
        cin >> option;
        switch (option)
        {
            case 1:
            getInfix(infix,n);
            break;

            case 2:
            convertInfix(infix,n);
            break;

            case 3:
            evalPostfix(infix,n);
            break;

            case 4:
            cout << "Exiting";
            break;
        }
    }
    return 0;
}
