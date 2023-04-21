#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
// int main()
// {
//     int a[]={3,1,2};
//     next_permutation(a,a+3);
//     cout<<a[0]<<" "<<a[1]<<" "<<a[2];
//     return 0;
// }

void  inbulit(vector<int> A)
{
     int a[]={3,1,2};
    next_permutation(a,a+3);
    cout<<a[0]<<" "<<a[1]<<" "<<a[2];
}


vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    // inbulit(A);
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]\n";
    return 0;
}