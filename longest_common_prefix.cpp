#include<iostream>
#include<vector>
#include<strings.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
       
         for(int i=0;i<strs[0].length();i++)
         {
             
             bool m=true;
             for(int j=1;j<strs.size();j++)
             {
                 if(strs[j].length()<=i||strs[j][i]!=strs[0][i])
                 {
                   
                     m=false;
                     break;
                 }
             }
             if(m)
             {
                
                 s+=strs[0][i];
             }
             else
             {
                 break;
             }
         }
          return s;
    }
   
};