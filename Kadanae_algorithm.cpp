
//Kadane's Algorithm
//It is greedy as well as DP
//it works only for array with mixture of -ve and +ve numbers
//Time complexity is O(n)

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int n;

    cout << "Enter Number of array\n ";
    cin >> n;
    int a[n];
    cout << "Enter numbers\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max_sum = 0, prev_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prev_sum += a[i];
        if (prev_sum > max_sum)
        {
            max_sum = prev_sum;
        }
        if (prev_sum < 0)
        {
            prev_sum = 0;
        }
    }
    cout << "Maximum sub array sum is : " << max_sum << endl;
    return 0;
}