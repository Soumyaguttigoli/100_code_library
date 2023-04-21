//we have to check wheather, we can get required sum from given numbers

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cout<<"Enter Number of elements\n";
    cin>>N;
    int sum;
    cout<<"Enter sum\n";
    cin>>sum;
    vector<int>arr(N);
    cout<<"Enter the elements\n";
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    vector<vector<int>>DP(N+1,vector<int>(sum+1,0));
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0&&j==0||j==0)
            {
                DP[i][j]=1;
            }
            else if(i==0)
            {
                DP[i][j]=0;
            }
            else if(DP[i-1][j]==1)
            {
                DP[i][j]=1;
            }
            else if(arr[i-1]>j)
            {
                DP[i][j]=0;
            }
            else{
                DP[i][j]=DP[i-1][j-arr[i-1]];
            }
            // cout<<DP[i][j]<<" ";

        }
        // cout<<endl;
    }

    if(DP[N][sum]==1)
    {
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}