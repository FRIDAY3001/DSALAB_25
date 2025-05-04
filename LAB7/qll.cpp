#include <iostream>
#include <cstdlib>

using namespace std;

class SLL {
private:
    struct Node {
        int data;
        Node* link;
    } *front, *rear;

public:
    SLL() {
        front = rear = NULL;
    }

    bool isempty() {
        return (front == NULL);
    }

    void enqueue(int num) 
    {
        Node* newnode = new Node;
        newnode->data = num;
        newnode->link = NULL;
        
        if (rear != NULL) {
            rear->link = newnode;
        }
        rear = newnode;

        if (front == NULL) 
        {
            front = newnode;
        }
    }

    int dequeue() 
    {
        if (isempty()) 
        {
            cout << "The queue is empty!!\n";
            return -1;
        }

        int deletedval = front->data;
        Node* temp = front;
        front = front->link;
        
        if (front == NULL) 
        {
            rear = NULL;
        }
        
        free(temp);
        return deletedval;
    }

    int peek() {
        if (isempty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isempty()) {
            cout << "The queue is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->link;
        }
        cout << "NULL\n";
    }
};

int main() {
    SLL q;
    int choice, value, result;

    while (true) {
        cout << "\nMENU\n1.Enqueue\n2.Dequeue.\n3.Peek\n4. Display\n5.Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to be inserted into the queue: ";
                cin >> value;
                q.enqueue(value);
                q.display();
                break;

            case 2:
                result = q.dequeue();
                if (result != -1) {
                    cout << "The deleted element is: " << result << "\n";
                }
                q.display();
                break;

            case 3:
                result = q.peek();
                if (result != -1) {
                    cout << "The element on the front is: " << result << "\n";
                }
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid Choice!!!\n";
        }
    }

    return 0;
}
