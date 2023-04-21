#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cout << "Enter number of elements in array : ";
    cin >> N;
    vector<int> array(N);
    cout << "Enter the elements\n";
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    // if number of elements are less than 3 we can't form mountain
    if (N < 3)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 1; i < N-1;)
    {
        if (array[i] > array[i - 1] && array[i] > array[i + 1])
        {
            int count = 0;
            int j = i;
            //go to left side 
            while (array[j] > array[j - 1] && j > 0)
            {
                j--;
                count++;
            }
            //go towards right side
            while (array[i] > array[i + 1] && i <= N - 2)
            {
                count++;
                i++;
            }
            ans = max(ans, count);
          
        }
        else
        {
            i++;
        }
    }
    if (ans > 0)
    {
        cout << ans + 1;
    }
    else
    {
        cout << ans;
    }

    return 0;
}