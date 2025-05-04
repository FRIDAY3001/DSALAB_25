#include <iostream>
using namespace std;

class Hash
{
    private:

    class Node
    {
        public:
        int key;
        Node* next;

        Node(int k)
        {
            key = k;
            next = nullptr;
        }
    };


    Node* hashtable[10];

    int function(int key)
    {
        return key%10;
    }


    public:

    void chaining() 
    {
        for (int i = 0; i < 10; i++) 
        {
            hashtable[i] = nullptr;
        }
    }


    void insert(int key)
    {
        int index = function(key);
        Node* newNode = new Node(key);

        newNode->next = hashtable[index];
        hashtable[index] = newNode;

        cout << "key inserted into table.\n";
    }


    void Delete(int key) 
    {
        int index = function(key);
        Node* cur = hashtable[index];
        Node* prev = nullptr;

        while (cur != nullptr) 
        {
            if (cur->key == key) 
            {
                if (prev == nullptr) 
                {
                    hashtable[index] = cur->next;
                } 
                else 
                {
                    prev->next = cur->next;
                }

                delete cur;
                cout << "key deleted from table\n";
                return;
            }

            prev = cur;
            cur = cur->next;
        }

        cout << "key not found.\n";
    }


    int search(int key) 
    {
        int index = function(key);
        Node* cur = hashtable[index];
        while (cur != nullptr) 
        {
            if (cur->key == key) 
            {
                return index;
            }
            cur = cur->next;
        }

        return -1;
    }

    // void display() 
    // {
    //     for (int i = 0; i < 10; i++) 
    //     {
    //         cout << i << " -> ";
    //         Node* current = hashtable[i];
    //         if (!current) 
    //         {
    //             cout << "value empty";
    //         }
    //         while (current != nullptr) 
    //         {
    //             cout << current->key;
    //             if (current->next != nullptr) cout << " -> ";
    //             current = current->next;
    //         }
    //         cout << "\n";
    //     }
    // }

    
};


int main() {
    int option, key;
    Hash h;
    h.chaining();

    while (option != 4) {
        cout << "\nMenu:\n1.Insert\n2.Delete\n3.Search\n4.Exit\n";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                h.insert(key);
                break;

            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                h.Delete(key);
                break;

            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                cout << h.search(key) << "\n";
                break;

            case 4:
                cout << "exiting.\n";
                break;
        }
    }

    return 0;
}