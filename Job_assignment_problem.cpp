//provde opmtimal assignment of 'N' jobs to 'N' people.

#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<vector<int>> vec(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)//rows are considered as no of people
    {
        for (int j = 0; j < N; j++)//columns are considered asjobs
        {
            cin >> vec[i][j];
        }
    }
    vector<int> dp((pow(2, N)), INT_MAX);
    dp[0] = 0;

    for (int mask = 0; mask < pow(2, N)-1; mask++)
    {
        bitset<1000000> bit;
        bit = mask;
        int x = bit.count();//no of bit set represent the person
        for (int j = 0; j < N; j++)
        {
            if (mask != (1 << j))//if both mask and (1<<j) is same, there going to be no change in value
            {
                dp[(mask | (1 << j))] = min(dp[(mask | (1 << j))], dp[mask] + vec[x][j]);
                
            }
        }
    }
    cout<<dp[pow(2,N)-1];
    return 0;
}