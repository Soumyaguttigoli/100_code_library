#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int N;
        cin>>N;
        int prof[N];
        for(int j=1;j<=N;j++)
        {
            cin>>prof[j];
        }
        int q;
        cin>>q;
        while(q>0)
        {
            int type;
            cin>>type;
            if(type==1)
            {
                int x,k;
                cin>>x>>k;
                prof[x]=k;
            }
            else if(type==0)
            {
                int x,y,k;
                cin>>x>>y>>k;
                int temp[y-x+1];
                temp[1]=prof[x];
                for(int l=x+1;l<=y;l++)
                {
                    int s=l-1;
                    int v=prof[l];
                    while(s>=1&&temp[s]>v)
                    {
                        temp[s+1]=temp[s];
                        s--;
                    }
                    temp[s+1]=v;
                }
                
                cout<<temp[k]<<endl;
            }
            q--;
        }
    }
    return 0;
}