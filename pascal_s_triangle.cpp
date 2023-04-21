#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vect(numRows);
         vect[0]=vector<int>(1);
        vect[0][0]=1;
        for(int i=1;i<numRows;i++)
        {
            vect[i]=vector<int>(i+1);
            
            vect[i][0]=1;
            vect[i][i]=1; 
            for(int j=1;j<i;j++)
            {
                // cout<<"j-hello\n";
                vect[i][j]=vect[i-1][j-1]+vect[i-1][j];
            }
        }
        return vect;
    }
};
//vec[i].resize(i+1,1)