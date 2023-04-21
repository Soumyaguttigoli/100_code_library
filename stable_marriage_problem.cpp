#include <bits/stdc++.h>
using namespace std;

bool womenPrefernceoverman(vector<vector<int>> prefer, int w, int curman, int man)
{

    for (int i = 0; i < prefer[0].size(); i++)
    {
        if (prefer[w][i] == curman)
        {
            cout << "Hello\n";
            return true;
        }
        if (prefer[w][i] == man)
        {
            cout << "hi\n";
            return false;
        }
    }
}

void stableMarriage(vector<vector<int>> prefer, int N)
{
    int womenP[N];
    bool menP[N];
    memset(womenP, -1, sizeof(womenP));
    memset(menP, false, sizeof(menP));
    int freemen = N;
    while (freemen > 0)
    {
        int man;
        for (man = 0; man < N; man++)
        {
            if (menP[man] == false)
            {
                break;
            }
        }

        for (int i = 0; (i < N) && (menP[man] == false); i++)
        {
            int w = prefer[man][i];
           
            if (womenP[w - N] == -1)
            {
                cout << "marry\n";
               
                womenP[w - N] = man;
                menP[man] = true;
                freemen--;
            }
            else
            {
                // if women is not free
                // check her preferences
                int curMan = womenP[w - N];
                
                if (womenPrefernceoverman(prefer, w, curMan, man) == false)
                {

                    womenP[w - N] = man;
                    menP[man] = true;
                    
                    menP[curMan] = false;
                    cout << "hellooooo";
                }
            }
        }
    }
    cout << "Women\tmen\n";
    for (int i = 0; i < N; i++)
    {
        cout << " " << i + N << "\t" << womenP[i] << endl;
    }
}

int main()
{
    int N;
    cout << "Enter number of men/women\n";
    cin >> N;
    vector<vector<int>> prefer(2 * N, vector<int>(N));
    // 0-(N-1) are men prefernces
    // N - (2*N-1) women prefernces
    for (int i = 0; i <= 2 * N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> prefer[i][j];
        }
    }
    stableMarriage(prefer, N);
    return 0;
}