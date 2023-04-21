#include <iostream>
#include <vector>
using namespace std;
 
// Recursive top-down function to count the total number of paths
// to reach cell (m, n) from cell (0, 0) and has given the cost
int countPaths(vector<vector<int>> const &mat, int m, int n, int cost)
{
    // base case
    if (cost < 0) {
        return 0;
    }
 
    // if we are at the first cell (0, 0)
    if (m == 0 && n == 0)
    {
        if (mat[0][0] - cost == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
 
    // if we are at the first row, we can only go left
    if (m == 0) {
        return countPaths(mat, 0, n - 1, cost - mat[m][n]);
    }
 
    // if we are at the first column, we can only go up
    if (n == 0) {
        return countPaths(mat, m - 1, 0, cost - mat[m][n]);
    }
 
    // recur to count total paths by going both left and top
    return countPaths(mat, m - 1, n, cost - mat[m][n]) +
            countPaths(mat, m, n - 1, cost - mat[m][n]);
}
 
int countPaths(vector<vector<int>> const &mat, int cost)
{
    // base case
    if (mat.size() == 0) {
        return 0;
    }
 
    // `M × N` matrix
    int M = mat.size();
    int N = mat[0].size();
 
    return countPaths(mat, M - 1, N - 1, cost);
}
 
int main()
{
    vector<vector<int>> mat =
    {
        { 4, 7, 1, 6 },
        { 5, 7, 3, 9 },
        { 3, 2, 1, 2 },
        { 7, 1, 6, 3 }
    };
 
    int cost = 25;
 
    cout << "Total paths with cost " << cost << " are " << countPaths(mat, cost);
 
    return 0;
}