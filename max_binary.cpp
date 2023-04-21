// Chef has a binary strings S of length N, and an integer K. Hitesh wants to maximize the decimal representation
//  of S using K operations of the following type: Type 1 Insert 0 at any position in the string.
// Type 2: Change any  0 to 1.
// Help Hitesh find the modified string with maximum possible decimal representation after performing at most K operations.

#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int N,K;
        cin>>N>>K;
        string s;
        cin>>s;
        for(int j=0;j<K;j++)
        {
            if(s[0]=='0')
            {
                s[0]='1';
            }
            else{
                s+='0';
            }
        }
        cout<<s<<endl;
    }
	return 0;
}
