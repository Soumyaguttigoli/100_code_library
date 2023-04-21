
#include <iostream>
#include <vector>
using namespace std;

//do right shift on 1 and loop for 32 times.
int count_bits(int n){
    
    // Initialising a variable count to 0.
    int total = 0;
    
    // Iterating over all the bits
    for(int i = 0 ; i < 32 ; i++){
        
        // (1<<i) corresponds to 2 raised to i
        if(n & (1<<i)){
            ++total;
        }
    }
    return total;
}

//using right shift on give number
int right_shift(int n)
{
    int total=0;
    while(n>0)
    {
        if(n&1)
        {
            total++;
        }
        n=n>>1;
    }

    return total;
}

int main(){

    int N;
    cin>>N;
    int ans=0;
    vector <int> arr(N);
   for(int i=0;i<N;i++)
   {
       cin>>arr[i];
    //    ans += count_bits(arr[i]);
    ans+=right_shift(arr[i]);

   }
    
    cout<<ans;
    return 0;
}