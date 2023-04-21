
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int arr[N+1];
    for(int i=1;i<=N;i++)
    {
        cin>>arr[i];
    }
    vector<int> visit(N+1,0);
    vector<vector<int>>vec;
    for(int i=1;i<=N;i++)
    {
        if(visit[i]!=1)
        {
            
            vector<int>temp;
            temp.push_back(i);
            visit[i]=1;
            int index=i;
            while(visit[arr[index]]!=1)
            { 
                    index=arr[index];
                    temp.push_back(index);
                    visit[index]=1;
            }
          temp.push_back(i);
            vec.push_back(temp);
        }
        
    }
    
    cout<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}