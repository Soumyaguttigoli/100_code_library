//First line is number of queries
//second line is input string
// next line queries
//if it is quesrry 1, replace all querry by given character
// if querry 2, check wheater palindrome is possible between given range from L to R
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string str;
    int N;
    cin >> str;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int q, l, r;
        char c;
        cin >> q >> l >> r;
        if (q == 1)
        {
            cin >> c;
            for (int j = l - 1; j < r; j++)
            {
                str[j] = c;
            }
            // cout<<str;
        }
        else if (q == 2)
        {
            int bitvector = 0, mask = 0;
            for (int i = 0; i<str.length(); i++)
            {
                int x = str[i] - 'a';

                mask = 1 << x;

                bitvector = bitvector ^ mask;
            }
            if ((bitvector & (bitvector - 1)) == 0)
            {
                cout << "Yes\n";
                
            }
            else
            {
                cout << "No\n";
            }
        }
    }
    return 0;
}