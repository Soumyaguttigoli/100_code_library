#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;
 
void findAllNumbers(int n)
{
    // find the cube root of `n`
    int cb = pow(n, 1.0 / 3);
 
    // create an empty set
    unordered_set<int> s;
 
    for (int i = 1; i < cb - 1; i++)
    {
        for (int j = i + 1; j < cb + 1; j++)
        {
            // (i, j) forms a pair
            int sum = (i*i*i) + (j*j*j);
 
            // sum is seen before
            if (s.find(sum) != s.end()) {
                cout << sum << endl;
            }
            else {
                // sum is not seen before
                s.insert(sum);
            }
        }
    }
}
 
int main()
{
    int n = 25000;
 
    findAllNumbers(n);
 
    return 0;
}