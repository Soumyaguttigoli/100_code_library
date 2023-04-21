#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string a[N];
    for(int i = 0;i < N;i++)
    {
        cin >> a[i];
    }

    int j;
    cin >> j;
    string c[j];
    for(int i = 0;i < j;i++)
    {
        cin >> c[i];
    }

    int count[j];
    for(int i = 0;i < j;i++)
    {
        count[i] = 0;
    }

    for(int i = 0;i < N;i++)
    {
        for(int k = 0;k <j;k++)
        {
            if(a[i] == c[k])
            {
                count[k]++;
            }
        }
    }

    for(int i = 0;i < j;i++)
    {
        cout << count[i] << endl;
    }
}