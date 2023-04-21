
// Add x to your current score and double the value of x.
// help geek by giving largest value for x ans score should be exactly equal to n, if not possible retutn print -1;
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long ans = -1;
    for (long long i = n / 3; i >= 1; i--)
    {
        long long sum = 0, c = 0;

        long long x = i;
        while (x < n && sum < n)
        {
            sum += x;
            c++;
            if (c >= 2 && sum == n)
            {

                cout << i;
                exit(0);
            }
            x = x * 2;
        }
    }
    cout << "-1\n";
    return 0;
}
