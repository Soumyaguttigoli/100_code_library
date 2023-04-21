#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// Function to find all common elements present in every row
// of a given matrix
void findCommonElements(vector<vector<int>> const &mat)
{
    // base case
    if (mat.size() == 0) {
        return;
    }
 
    // `M × N` matrix
    int M = mat.size();
    int N = mat[0].size();
 
    // Create an empty map
    unordered_map<int, int> map;
 
    // Insert all elements of the first row into the map
    // with their value set as 1
 
    for (int c = 0; c < N; c++) {
        map.insert(pair<int, int>(mat[0][c], 1));
    }
 
    // Do for remaining rows
    for (int r = 1; r < M; r++)
    {
        for (int c = 0; c < N; c++)
        {
            // Get the current element
            int curr = mat[r][c];
 
            // If the current element is present on the map and its value
            // is the same as the row index, increment its value by 1.
            // This check also handles duplicate entries in the same row.
 
            if (map.find(curr) != map.end() && map[curr] == r) {
                map[curr] = r + 1;
            }
        }
    }
 
    // Iterate over each entry in the map and print keys having
    // their value equal to `M` (number of rows in the matrix)
 
    cout << "The common elements are: ";
    for (auto it: map)
    {
        if (it.second == M) {
            cout << it.first << " ";
        }
    }
}
 
int main()
{
    vector<vector<int>> mat =
    {
        { 7, 1, 3, 5, 3, 6 },
        { 2, 3, 6, 1, 1, 6 },
        { 6, 1, 7, 2, 1, 4 },
        { 6, 6, 7, 1, 3, 3 },
        { 5, 5, 6, 1, 5, 4 },
        { 3, 5, 6, 2, 7, 1 },
        { 4, 1, 4, 3, 6, 4 },
        { 4, 6, 1, 7, 4, 3 }
    };
 
    findCommonElements(mat);
 
    return 0;
}
