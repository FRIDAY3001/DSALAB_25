#include <iostream>
using namespace std;

class Hash 
{
    private:
    int hashtable[10];
    bool values[10];

    int function(int key) 
    {
        return key % 10;
    }

    public:
    void quadratic() 
    {
        for (int i = 0; i < 10; i++) 
        {
            values[i] = false;
        }
    }

    void insert(int key) 
    {
        int index = function(key);
        int i = 0;
        int ind = index;

        while (values[ind]) 
        {
            i++;
            if (i == 10) 
            {
                cout << "The hash table is full.\n";
                return;
            }

            ind = (index + i * i) % 10;
        }

        hashtable[ind] = key;
        values[ind] = true;
        cout << "key inserted into table.\n";
    }

    void Delete(int key) 
    {
        int index = function(key);
        int i = 0;
        int ind;
    
        while (i < 10) 
        {
            ind = (index + i * i) % 10;
    
            if (values[ind] && hashtable[ind] == key) 
            {
                values[ind] = false;
                cout << "key deleted from table";
                return;
            }
    
            if (!values[ind]) 
            {
                break;
            }
    
            i++;
        }
    
        cout << "key not found.\n";
    }



    int search(int key) 
    {
        int index = function(key);
        int i = 0;
        int ind;
    
        while (i < 10) 
        {
            ind = (index + i * i) % 10;
    
            if (values[ind] && hashtable[ind] == key) 
            {
                return ind;
            }
    
            if (!values[ind]) 
            {
                break;
            }
    
            i++;
        }
    
        return -1;
    }
    

    void display() 
    {
        for (int i = 0; i < 10; i++) 
        {
            if (values[i] == true) 
            {
                cout << i << " -> " << hashtable[i] << "\n";
            } 
            else 
            {
                cout << "value empty\n";
            }
        }
    }

};


int main() 
{
    int option, key;
    Hash h;
    h.quadratic();

    while (option != 5) 
    {
        cout << "\nMenu:\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n";
        cin >> option;

        switch (option) 
        {
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
                h.display();
                break;

            case 5:
                cout << "exiting.\n";
                break;
        }
    }

    return 0;
}
