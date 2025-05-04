#include <iostream>
using namespace std;

class Queue {
private:
    int arr[5];
    int front;
    int rear;
    int size;

public:
    Queue() {
        size = 0;
        front = -1;
        rear = -1;
    }

    void enqueue(int num) {
        if (size == 5) {
            cout << "The queue is full.\n";
            return;
        }

        if (front == -1) { // First element being inserted
            front = 0;
        }
        rear++;
        arr[rear] = num;
        size++;
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return -1;
        }

        int deletedValue = arr[front];

        if (front == rear) { // If last element is removed
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        size--;
        return deletedValue;
    }

    int peek() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, value, result;

    while (true) {
        cout << "1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert into queue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                result = q.dequeue();
                if (result != -1)
                    cout << "The dequeued element is: " << result << "\n";
                break;

            case 3:
                result = q.peek();
                if (result != -1)
                    cout << "The element at the front is: " << result << "\n";
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << "Exiting.\n";
                return 0;

            default:
                cout << "Invalid Choice. Exiting...\n";
                return 0;
        }
    }
}
