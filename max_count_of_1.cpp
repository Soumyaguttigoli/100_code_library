// You are given a binary string S of length N. You have to construct a binary string X, of length N, such that:
// For each (1≤i<N), (+1)=(⊕)X (i+1)=(X i⊕S i ), where ⊕ denotes the bitwise XOR operation;
// The count of 1s in the string X is maximised


#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   long int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        long int N;
        cin>>N;
        string s;
        cin>>s;
        long int x1[N],x2[N];
        int count1=0,count2=1;
        x1[0]=0;
        x2[0]=1;
        for(long int j=0;j<N-1;j++)
        {
            if(s[j]=='0')
            {
                x1[j+1]=x1[j]^0;
                x2[j+1]=x2[j]^0;
            }
            else{
                 x1[j+1]=x1[j]^1;
                 x2[j+1]=x2[j]^1;
            }
            if(x1[j+1]==1)
            {
                count1++;
            }
            else if(x2[j+1]==1)
            {
                count2++;
            }
        }
        if(count1>count2)
        {
            cout<<count1<<endl;
        }
        else{
            cout<<count2<<endl;
        }
    }
}
