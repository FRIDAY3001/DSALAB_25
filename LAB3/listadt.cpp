// implement list adt using an array of size 5 using classes
#include<iostream>
using namespace std;
class List 
{
    private:
    int arr[5];
    int current;

    public:
    List() {
        current = -1;
    }
    

    void insertBeginning(int element)
    {
        if (current == 4)
        {
            cout << "The list is full.";
        }
        for (int i = current+1;i > 0;i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = element;
        current++;
    }

    void insertEnd(int element)
    {
        if (current == 4)
        {
            cout << "List is full.";
        }
        else
        {
            arr[current+1] = element;
            current++;
        }
    }

    void insertPosition(int element, int position)
    {
        for (int i = current+1; i > position;i--) 
        {
            arr[i] = arr[i-1];
        }
        arr[position] = element;
        current++;
    }

    int deleteBeginning()
    {
        int element = arr[0];
        for (int i = 0;i < current;i++) 
        {
            arr[i] = arr[i+1];
        }
        current--;
        return element;
    }

    int deleteEnd()
    {
        if (current == -1)
        {
            cout << "List is empty.";
        }
        else
        {
        current--;
        }
        return 0;
    }

    int deletePosition(int position)
    {
        for (int i = position;i < current;i++)
        {
            arr[i] = arr[i+1];
        }
        current--;

        return 0;
    }

    int search(int key)
    {
        for (int i = 0;i < current+1;i++)
        {
            if (arr[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    void display()
    {
        for (int i = 0;i < current+1;i++) 
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    int rotate(int k)
    {
        for (int i = 0;i < k;i++)
        {
            int temp = arr[current];
            for (int j = current; j >= 0; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[0] = temp;
        }



        return 0;
    }
    
};

int main()
{
    int option,value,position,key,rotation;
    List arr;

    while(option != 10)
    {
        cout << "Menu:\n 1. Insert at the beginning\n 2. Insert at the End\n 3. Insert at a position\n 4. Delete at the beginning\n 5. Delete at the End\n 6. Delete at a position\n 7. Search\n 8. Display\n 9. Rotate\n 10. Exit\n";
        cin >> option;
        switch (option)
        {
            case 1:
                cout << "Enter a number:";
                cin >> value;
                arr.insertBeginning(value);
                break;

            case 2:
                cout << "Enter a number:";
                cin >> value;
                arr.insertEnd(value);
                break;

            case 3:
                cout << "Enter a number:";
                cin >> value;
                cout << "Enter a position to insert:";
                cin >> position;
                arr.insertPosition(value,position);
                break;

            case 4:
                arr.deleteBeginning();
                break;

            case 5:
                arr.deleteEnd();
                break;

            case 6:
                cout << "Enter a position to delete:";
                cin >> position;
                arr.deletePosition(position);
                break;
            
            case 7:
                cout << "Enter a number to search:";
                cin >> key;
                int ans;
                ans = arr.search(key);
                if (ans == -1)
                {
                    cout << "element not found.";
                }
                else
                {
                    cout << ans;
                }
                break;

            case 8:
                arr.display();
                break;


            case 9:
                cout << "Enter a number to rotate by:";
                cin >> rotation;
                printf("above rotation\n");
                arr.rotate(rotation);
                printf("below rotation\n");
                break;
            
            case 10:
                break;

            default:
                break;

        }
    }

}
