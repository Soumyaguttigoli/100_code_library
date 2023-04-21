#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Recursive function to perform preorder traversal on the tree and
// fill the map with diagonal elements
void printDiagonal(Node *node, int diagonal, auto &map)
{
    // base case: empty tree
    if (node == nullptr)
    {
        return;
    }

    // insert the current node into the current diagonal
    map[diagonal].push_back(node->data);

    // recur for the left subtree by increasing diagonal by 1
    printDiagonal(node->left, diagonal + 1, map);

    // recur for the right subtree with the same diagonal
    printDiagonal(node->right, diagonal, map);
}

// Function to print the diagonal elements of a given binary tree
void printDiagonal(Node *root)
{
    // create an empty map to store the diagonal element in every slope
    unordered_map<int, vector<int>> map;

    // perform preorder traversal on the tree and fill the map
    printDiagonal(root, 0, map);

    // traverse the map and print the diagonal elements
    for (int i = 0; i < map.size(); i++)
    {
        for (int j : map[i])
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    printDiagonal(root);

    return 0;
}