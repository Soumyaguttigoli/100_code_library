#include<bits/stdc++.h>
using namespace std;

int heightChecker(vector<int>& heights)
{
    vector<int>g;
    for(int i = 0; i < heights.size(); i++)
    {
        g.push_back(heights[i]);
    }

    sort(heights.begin(),heights.end());
    int count = 0;
    for(int i = 0; i < heights.size(); i++)
    {
        if(g[i] != heights[i])
            count++;
    }

    return count;
}

int main()
{
    int N;
    cin >> N;
    vector<int>a;
    for(int i = 0; i < N; i++)
    {
        int f;
        cin >> f;
        a.push_back(f);
    }

    int r = heightChecker(a);
    cout << r << endl;
}