

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};

typedef struct Tree Tree;

Tree *insert_bst_tree(Tree *root, int data)
{
    Tree *newNode = (Tree *)malloc(sizeof(Tree));
    if (newNode == NULL)
    {
        cout << "Memory is not allocated\n";
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        Tree *curr = root;
        Tree *parent = NULL;
        while (curr != NULL)
        {
            parent = curr;
            if (curr->data > newNode->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        if (parent->data > newNode->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }
    return root;
}

// Delete directly node, if data ata leaf node
// if data present at node which has 1 child, delete node and attach it's child to it's grand parent;
// if data present at node which 2 children, then anyone method from folowing:
//   1)In-order precessor: in-place of removed node attach the largest element from it's left.
//   2)In-order successor: in-place of removed node attach the smallest element from it's right.
Tree *Delete_node(Tree *root, int data)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return root;
    }
    else
    {
        Tree *curr = root;
        Tree *parent = NULL;
        while (curr != NULL && curr->data != data)
        {
            parent = curr;
            if (curr->data > data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        Tree *p = NULL;
        if (curr == NULL)
        {
            cout << "Data is not present in Tree\n";
        }
        else if (curr->left == NULL)
        {
            p = curr->right;
        }
        else if (curr->right == NULL)
        {
            p = curr->left;
        }
        else
        {
            Tree *successor = curr->right;
            while (successor->left != NULL)
            {
                successor = successor->left;
            }
            successor->left = curr->left;
            p = curr->right;
        }
        if (parent == NULL)
        {
            free(curr);
            return p;
        }
        else if (curr = parent->left)
        {
            parent->left = p;
        }
        else
        {
            parent->right = p;
        }
        free(curr);
        return root;
    }
}

void in_order(Tree *root)
{
    if (root != NULL)
    {
        in_order(root->left);
        cout << root->data << " ";
        in_order(root->right);
    }
}
void post_order(Tree *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        cout << root->data << " ";
    }
}
void pre_oder(Tree *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        pre_oder(root->left);
        pre_oder(root->right);
    }
}

int main()
{
    int choice;
    Tree *root = NULL;
    while (1)
    {
        cout << "1-inset\n";
        cout << "2-delete\n";
        cout << "3-inorder\n";
        cout << "4-post order\n";
        cout << "5-pre-order\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter data\n";
            cin >> data;
            root = insert_bst_tree(root, data);
            break;
        case 2:
            int data1;
            cout << "Enter data to be deleted\n";
            cin >> data1;
            root = Delete_node(root, data1);
            break;
        case 3:
            in_order(root);
            break;
        case 4:
            post_order(root);
            break;
        case 5:
            pre_oder(root);
            break;
        case 6:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}