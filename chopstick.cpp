// Actually, the two sticks in a pair of chopsticks need not be of the same length. A pair of sticks can
//  be used to eat as long as the difference in their length is at most D. The Chef has N sticks in which the ith stick is L[i] units long.
//   A stick can't be part of more than one
//  pair of chopsticks. Help the Chef in pairing up the sticks to form the maximum number of usable pairs of chopsticks.


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,D;
	cin>>N>>D;
	int L[N];
	for(int i=0;i<N;i++)
	{
	    cin>>L[i];
	}
	 int chopsticks_count=0;
	 sort(L,L+N);
	 for(int i=0;i<N;i++)
	 {
	     int sum;
	     sum=L[i]-L[i+1];
	     if(sum<=D&&sum>=(-D))
	     {
	         chopsticks_count++;
	         i++;
	     }
	 }
	 cout<<chopsticks_count;
	 
	 
	return 0;
}
