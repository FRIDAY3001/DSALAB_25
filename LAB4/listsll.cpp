#include <iostream>
#include "list.h"

int main()
{
    List l1, l2, mergedList;
    int value, option, ans;

    while (1)
    {
        cout << "\n1. Insert element\n";
        cout << "2. Merge lists\n";
        cout << "3. Display merged list\n";
        cout << "4. Exit\n";
        cout << "Enter an option: ";
        cin >> option;

        if (option == 1)
        {
            cout << "Enter an element to insert: ";
            cin >> value;

            cout << "Insert into list 1 or 2: ";
            cin >> ans;
            if (ans == 1)
            {
                l1.insertAscending(value);
            }
            else if (ans == 2)
            {
                l2.insertAscending(value);
            }
            else
            {
                cout << "Invalid list number!\n";
            }
        }
        else if (option == 2)
        {
            mergedList = List::merge(l1.gethead(), l2.gethead());
            cout << "Lists merged\n";
        }
        else if (option == 3)
        {
            mergedList.display();
        }
        else if (option == 4) // Exit only when option 4 is chosen
        {
            break;
        }
        else
        {
            cout << "Invalid option! Try again.\n";
        }
    }

    return 0;
}
