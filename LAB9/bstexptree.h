#ifndef BST_H
#define BST_H

#include <iostream>
#include<stack>
using namespace std;

class Tree {
private:
    struct node {
        char data;
        struct node* left;
        struct node* right;
    };

    node* root;  

public:
    Tree() 
    {
        root = NULL;
    }


    struct node* createNode(char element) 
    {
        node* newnode = new node;
        newnode->data = element;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }


    struct node* insert(struct node* root, char key) 
    {
        if (root == NULL) 
        {  
            return createNode(key);
        }
        if (key < root->data) 
        {
            root->left = insert(root->left, key);
        } 
        else 
        {
            root->right = insert(root->right, key);
        }
        return root;
    }

   
    void Insert(char x) 
    {
        root = insert(root, x);  
    }

    void Inorder_traversal() 
    {
        inorder_traversal(root);
        cout << "\n";
    }

    void inorder_traversal(struct node* root) 
    {
        if (root == NULL) 
        {
            return;
        }
        inorder_traversal(root->left);
        cout << root->data << "  ";
        inorder_traversal(root->right);
    }

    void Preorder_traversal() 
    {
        preorder_traversal(root);
        cout << "\n";
    }

    void preorder_traversal(struct node* root) 
    {
        if (root == NULL) 
        {
            return;
        }
        cout << root->data << "  ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }


    void Postorder_traversal() 
    {
        postorder_traversal(root);
        cout << "\n";
    }

    void postorder_traversal(struct node* root) 
    {
        if (root == NULL) 
        {
            return;
        }
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->data << "  ";
    }

    string getPostfixExpression() 
    {
        string postfix;
        cout << "Enter a valid postfix expression: ";
        cin >> postfix;
        return postfix;
    }
    
    void constructExpressiontree() 
    {
        string postfix = getPostfixExpression();
        stack<node*> st;
    
        for (int i = 0; i < postfix.length(); i++) 
        {
            char ch = postfix[i];

            node* newNode = new node;
            newNode->data = ch;
            newNode->left = NULL;
            newNode->right = NULL;
    
            if (ch >= '0' && ch <= '9') 
            {
                st.push(newNode);
            }
            else
            {
                node* newNode = new node;
                newNode->data = ch;
    
                if (!st.empty()) 
                {
                    newNode->right = st.top();
                    st.pop();
                }
                if (!st.empty()) 
                {
                    newNode->left = st.top();
                    st.pop();
                }
    
                st.push(newNode);
            }
        }
        if (!st.empty()) 
        {
            root = st.top();
            st.pop();
        }
    }
};

#endif