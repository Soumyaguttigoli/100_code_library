#include <iostream>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
// Function to print all nodes of a given level from left to right
bool printLevelLeftToRight(Node* root, int level)
{
    if (root == nullptr) {
        return false;
    }
 
    if (level == 1)
    {
        cout << root->key << " ";
        return true;
    }
 
    // process left child before the right child
    bool left = printLevelLeftToRight(root->left, level - 1);
    bool right = printLevelLeftToRight(root->right, level - 1);
 
    return left || right;
}
 
// Function to print all nodes of a given level from right to left
bool printLevelRightToLeft(Node* root, int level)
{
    if (root == nullptr) {
        return false;
    }
 
    if (level == 1)
    {
        cout << root->key << " ";
        return true;
    }
 
    // process right child before the left child
    bool right = printLevelRightToLeft(root->right, level - 1);
    bool left = printLevelRightToLeft(root->left, level - 1);
 
    return right || left;
}
 
// Function to print level order traversal of a given binary tree
void spiralOrderTraversal(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    // start from level 1 — till the height of the tree
    int level = 1;
 
    // run till either function returns false
    while (printLevelLeftToRight(root, level++) &&
        printLevelRightToLeft(root, level++));
}
 
int main()
{
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
 
    spiralOrderTraversal(root);
 
    return 0;
}
