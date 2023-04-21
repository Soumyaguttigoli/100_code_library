
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string str;
    int K, c = 0;
    cin >> str >> K;
    int j = 0;
    while (j < str.length() - 1 && c < K)
    {

        if (str[j] < str[j + 1])
        {
            str.erase(str.begin() + j);
            c++;
            if (j == 0)
            {
                j = 0;
            }
            else
            {
                j--;
            }
        }
        j++;
    }

    if (c < K)
    {
        str.erase(str.size() - (K - c), str.size() - 1);
    }

    cout << str;
    return 0;
}