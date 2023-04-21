//Only one disk will be moved at time
//only uppermost disk will be movced 
// no disk wll be placed on  smaller disk 
// Whole disks has to be moved to other disk

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Tower(int N,char from,char to, char Aux)
{
    if(N==1)
    {
        cout<<"Move disk 1 from "<<from<<" to "<<to<<endl;
        return ;
    }
    Tower(N-1,from, Aux,to);
    cout<<"Move Disk "<<N<<" from "<<from<<" to "<<to<<endl;
    Tower(N-1,Aux,to,from);
}
int main()
{
    int N;
    // char A,B,C;
    cin>>N;
    Tower(N,'A','C','B');
    return 0;
}