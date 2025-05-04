//stack ADT using sll header file
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace  std;

class stack 
{
    private:

    class node
    {
        public:        
        char data;
        node* next;
    }*top = NULL;
    public:

    void push(char element)
    {
        node* newnode = new node;
        newnode->data = element;
        newnode->next = top;
        top = newnode;

    }

    char pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty.\n";
            return '\0';
        }
        else if (top->next == NULL)
        {
            node* temp = top;
            char value = top->data;
            delete temp;
            top = NULL;
            return value;
        }
        else
        {
            char value = top->data;
            node* temp = top;
            top = top->next;
            delete temp;
            return value;
            }
    }

    char peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty.\n";
            return '\0';
        }
        else
        {
            return top->data;
        }
    }
};

#endif
