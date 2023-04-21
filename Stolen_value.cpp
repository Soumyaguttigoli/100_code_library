#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int dp[N + 1],sv[N + 1];
    for(int i = 1;i <= N;i++)
    {
        cin >> sv[i];
    }

    dp[0] = 0;
    dp[1] = sv[1];
    for(int i = 2;i <= N;i++)
    {
        dp[i] = max(dp[i - 2] + sv[i],dp[i - 1]);
    }

    cout << dp[N] << endl;

}