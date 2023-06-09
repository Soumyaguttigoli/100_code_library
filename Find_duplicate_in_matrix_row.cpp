#include <iostream>
using namespace std;
 
// `M × N` matrix
#define M 5
#define N 5
 
// Data structure to store a Trie node
struct Trie
{
    bool isLeaf;    // set when the node is a leaf node
    Trie* character[2];
};
 
// Function that returns a new Trie node
Trie* getNewTrieNode()
{
    Trie* node = new Trie;
 
    node->character[0] = node->character[1] = nullptr;
    node->isLeaf = false;
 
    return node;
}
 
// Iterative function to insert each array element into a Trie
bool insert(Trie*& head, bool* arr)
{
    // start from the root node
    Trie* curr = head;
 
    for (int i = 0; i < N; i++)
    {
        // create a new node if the path doesn't exist
        if (curr->character[arr[i]] == nullptr) {
            curr->character[arr[i]] = getNewTrieNode();
        }
 
        // go to the next node
        curr = curr->character[arr[i]];
    }
 
    // if the row is inserted before, return false
    if (curr->isLeaf) {
        return false;
    }
 
    // mark leaf node and return true
    return curr->isLeaf = true;
}
 
int main()
{
    bool mat[M][N] =
    {
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0}
    };
 
    // insert all rows of the matrix into a Trie
    Trie* head = getNewTrieNode();
    for (int i = 0; i < M; i++)
    {
        if (!insert(head, mat[i])) {
            cout << "Duplicate row found: Row #" << i + 1 << endl;
        }
    }
 
    return 0;
}
