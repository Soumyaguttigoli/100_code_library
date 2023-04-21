
//Follows the Catalon numbers.
//Catalon Number =(2N)!/(N+1)!*N!

//Montain Range Problem , and closed braket follows the same method

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cout<<"Enter number of grids\n";
    cin>>N;
    int res=1;
    for(int i=0;i<N;i++)
    {
        res*=2*N-i;
        res/=i+1;
    }
    cout<<"No of Dyck paths:";
    cout<<res/(N+1);
    return 0;
}