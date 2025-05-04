#include <iostream>
#include <stack>
#include "bstexptree.h"
using namespace std;


int main() {
    Tree t;
    int option;
    option = 0;
    while(option != 5)
    {
        cout << "Menu:\n 1.Get Postfix,Construct Expression Tree\n2.Preorder\n3.Inorder\n4.Postorder\n5.Exit\n";
        cin >> option;
        switch (option) {
            case 1:
                t.constructExpressiontree();
                cout << "Expression Tree Constructed!\n";
                break;

            case 2:
                cout << "Preorder: ";
                t.Preorder_traversal();
                break;

            case 3:
                cout << "Inorder: ";
                t.Inorder_traversal();
                break;

            case 4:
                cout << "Postorder: ";
                t.Postorder_traversal();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice, try again.\n";
        }
    }   
}
