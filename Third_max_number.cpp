#include<bits/stdc++.h>
using namespace std;

int thirdMax(vector<int>& nums)
{
    int index = 1;
    if(nums.size() == 1)
        return nums[0];
    else if(nums.size() == 2)
    {
        if(nums[0] > nums[1])
            return nums[0];
        else
            return nums[1];
    }
    // return nums[0] > nums[1];
    else
    {
        sort(nums.begin(),nums.end());
        int prev = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            if(prev != nums[i])
                nums[index++] = nums[i];
            prev = nums[i];
        }
    }

    if(index > 2)
        return nums[index - 3];
    else
    {
        if(nums[0] > nums[1])
            return nums[0];
        else
            return nums[1];
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int>a;
    for(int i = 0;i < N;i++)
    {
        int f;
        cin >> f;
        a.push_back(f);
    }

    int d = thirdMax(a);
    cout << d << endl;
}