#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER a as parameter.
 */

int solve(long n) {
    long fib[n+1];
    fib[0]=0;
    fib[1]=1;
    fib[2]=1;
    for(int i=3;i<=n;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    return fib[n];
   
    
}
int GCD(int a, int b)
{
    if (a == 0)
        return b;
    return GCD(b%a, a);
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
     int gcd=0;
     if(n>=1&&n<=200000)
     {
        for (int n_itr = 0; n_itr < n; n_itr++) {
        string a_temp;
        getline(cin, a_temp);

        long a = stol(ltrim(rtrim(a_temp)));

        // int result = solve(a);
        if(a>=1&&a<=1000000000000)
        {
             gcd=GCD(gcd,a);
        }
       
        }
        int result=solve(gcd);
        fout<<result%1000000007<<endl;
     }
    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
