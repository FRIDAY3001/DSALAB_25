#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class List
{
    private:
    struct node 
    {
        int data;
        struct node* next;
    }*head = NULL;

    public:

    struct node* gethead()
    {
        return head;
    }

    void insertAscending(int element)
    {
        struct node* newnode = new node(); 
        newnode->data = element;
        newnode->next = NULL; 

        if (head == NULL || head->data >= element)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        struct node* temp = head;
        while (temp->next != NULL && temp->next->data < element)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    static List merge(struct node* temp1, struct node* temp2) {
        List mergedList;

        while (temp1 != NULL) {
            mergedList.insertAscending(temp1->data);
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            mergedList.insertAscending(temp2->data);
            temp2 = temp2->next;
        }

        return mergedList;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }
        
        struct node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

#endif