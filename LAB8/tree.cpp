#include <iostream>
using namespace std;

class Tree {
private:
    struct node {
        int data;
        struct node* left;
        struct node* right;
    };

    node* root;  

public:
    Tree() 
    {
        root = NULL;
    }



    struct node* createNode(int element) {
        node* newnode = new node;
        newnode->data = element;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }


    struct node* insert(struct node* root, int key) {
        if (root == NULL) {  
            return createNode(key);
        }
        if (key < root->data) {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }
        return root;
    }

   
    void Insert(int x) {
        root = insert(root, x);  
    }

    void Inorder_traversal() {
        inorder_traversal(root);
        cout << "\n";
    }

    void inorder_traversal(struct node* root) {
        if (root == NULL) {
            return;
        }
        inorder_traversal(root->left);
        cout << root->data << "  ";
        inorder_traversal(root->right);
    }

    void Preorder_traversal() {
        preorder_traversal(root);
        cout << "\n";
    }

    void preorder_traversal(struct node* root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << "  ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }


    void Postorder_traversal() {
        postorder_traversal(root);
        cout << "\n";
    }

    void postorder_traversal(struct node* root) {
        if (root == NULL) {
            return;
        }
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->data << "  ";
    }

    bool Search(int key) {
        return search(root, key);
    }

    bool search(struct node* root, int key) {
        if (root == NULL) {
            return false;
        }
        if (root->data == key) {
            return true;
        }
        bool leftSearch = search(root->left, key);
        if (leftSearch) {
            return true;
        }
        return search(root->right, key);
    }

};

int main() {
    Tree t;
    int option,value,key;

    while(option != 6)
    {
        cout << "Menu:\n 1. Insert\n 2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\n";
        cin >> option;
        switch (option)
        {

            case 1:
            cout << "Enter an element: ";
            cin >> value;
            t.Insert(value);
            break;

            case 2:
            t.Preorder_traversal();
            break;

            case 3:
            t.Inorder_traversal();
            break;

            case 4:
            t.Postorder_traversal();
            break;

            case 5:
            cout << "Enter an element to search: ";
            cin >> key;
            if (t.Search(key)) 
            {
                cout << key << " found in tree.\n";
            } 
            
            else 
            {
                cout << key << " not found in tree.\n";
            }
            break;

            case 6:
            cout << "Exiting.";
            break;

        }
    }
    
}
