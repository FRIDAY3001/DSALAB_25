#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[5];
    int front;
    int rear;
    int size;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    void enqueue(int num) {
        if (size == 5) {
            cout << "The queue is full.\n";
            return;
        }

        if (front == -1) { // First element being inserted
            front = 0;
        }

        rear = (rear + 1) % 5;
        arr[rear] = num;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue is empty.\n";
            return -1;
        }

        int deletedValue = arr[front];

        if (front == rear) { // Last element being removed
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % 5;
        }

        size--;
        return deletedValue;
    }

    int peek() {
        if (size == 0) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % 5;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q;
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
