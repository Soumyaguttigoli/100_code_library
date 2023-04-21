// segment tree which returns the min value between given range
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int seg[10000],arr[1000];

//oit takesw parameters as index, lower bound and higher bound
void Build(int ind, int low, int high)
{
    if(low==high)
    {
      seg[ind]=arr[low];
      return;
    }
    int mid=(low+high)/2;
    Build(2*ind+1,low,mid);
    Build(2*ind+2,mid+1,high);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}

int querry(int ind ,int low,int high,int l,int h)
{
    if(low>=l&&h>=high)
    {
        return seg[ind];
    }
    else if(high<l||low>h)
    {
        return INT_MAX;
    }
    int mid=(low+high)/2;
    int left=querry(2*ind+1,low,mid,l,h);
    int right=querry(2*ind+2,mid+1,high,l,h);
    return min(left,right);
}
int main()
{
    int N;
    cout << "No of elements\n";
    cin >> N;
    cout << "Enter elements\n";
   
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    //build segment tree 
    Build(0, 0, N - 1);

    cout<<"Enter number of queries\n";
    int q;
    cin>>q;
    while(q>0)
    {
        int l,h;
        cout<<"Enter the range\n";
        cin>>l>>h;
      cout<<  querry(0,0,N-1,l,h)<<endl;
        q--;
    }
    return 0;
}