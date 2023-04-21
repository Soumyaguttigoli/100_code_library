#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string s1,s2;
    cout<<"Enter 2 strings\n";
    cin>>s1>>s2;
    long int LCS[s1.length()+1][s2.length()+1];
    for(int i=0;i<=s1.length();i++)
    {
        for(int j=0;j<=s2.length();j++)
        {
            if(i==0||j==0)
            {
                LCS[i][j]=0; 
            }
               else{
                if(s1[i]==s2[j])
                {
                    LCS[i][j]=LCS[i-1][j-1]+1;
                }
                else{
                    LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
                }
               }
        }
    }
    cout<<LCS[s1.length()][s2.length()];
    return 0;
}