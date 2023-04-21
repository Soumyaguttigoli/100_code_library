#include <iostream>
using namespace std;

const int MOD = 1e9 + 7; // modulo value

int main() {
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4; // input the quantities of the gems

    // Initialize the dynamic programming array
    int dp[5][5][5][5] = {0}; // dp[i][j][k][l] stores the number of valid arrangements up to the ith, jth, kth, and lth gems

    dp[0][0][0][0] = 1; // Base case: there is only one way to arrange zero gems

    // Iterate through all possible combinations of the gem quantities
    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            for (int k = 0; k <= n3; ++k) {
                for (int l = 0; l <= n4; ++l) {
                    if (i > 0) dp[i][j][k][l] = (dp[i][j][k][l] + dp[i - 1][j][k][l]) % MOD; // add arrangements with G1 gem
                    if (j > 0) dp[i][j][k][l] = (dp[i][j][k][l] + dp[i][j - 1][k][l]) % MOD; // add arrangements with G2 gem
                    if (k > 0) dp[i][j][k][l] = (dp[i][j][k][l] + dp[i][j][k - 1][l]) % MOD; // add arrangements with G3 gem
                    if (l > 0) dp[i][j][k][l] = (dp[i][j][k][l] + dp[i][j][k][l - 1]) % MOD; // add arrangements with G4 gem
                }
            }
        }
    }

    cout << dp[n1][n2][n3][n4] << endl; // print the final result
    return 0;
}
