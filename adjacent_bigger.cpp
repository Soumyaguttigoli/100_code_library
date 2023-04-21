#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int j =0;j<T;j++)
    {
        int N,K;
        cin>>N>>K;
        if((K-N)>=2||N<=1)
        {
            cout<<"-1\n";
        }
        else
        {
            if(K-N==1)
            {
                int i;
                for(i=0;i<(N/2);i++)
                {
                    cout<<i+1<<" "<<N-i<<" ";
                }
                if(N%2!=0)
                {
                    cout<<i+1;
                }

            }
            else if(K<=3)
            {
                int i;
                for(i=1;i<N;i++)
                {
                    cout<<i<<" ";
                }
                cout<<i;
            }
            else if(K==4)
            {
                cout<<"1"<<" "<<"3"<<" "<<"2"<<" ";
                int i;
                for(i=4;i<N;i++)
                {
                    cout<<i<<" ";
                }
                cout<<i;
            }
            else if(K<=N)
            {
                int i,L,f=0;
                if(K%2==0)
                {
                    L=K/2;
                    L=L-1;
                    f=1;
                }
                else
                {
                    L=K/2;
                }
                for(i=1;i<=L;i++)
                {
                    cout<<i<<" "<<K-i<<" ";
                }
                if(f)
                {
                    cout<<i<<" ";
                    int i;
                    for(i=K;i<N;i++)
                    {
                        cout<<i<<" ";
                    }
                    cout<<i;
                }
                else{
                    int i;
                    for(i=K;i<N;i++)
                    {
                        cout<<i<<" ";
                    }
                    cout<<i;
                }
            }
           
            
        }       
        cout<<endl;
    }
   return 0;
}