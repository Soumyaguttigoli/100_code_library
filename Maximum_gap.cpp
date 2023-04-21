    #include<bits/stdc++.h>
using namespace std;

int maximumGap(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    int max = -1;
    if(nums.size() == 1)
        return 0;
    else if(nums.size() == 2)
        return nums[1] - nums[0];

    else
    {
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i + 1] - nums[i] > max)
            {
                max = nums[i + 1] - nums[i];
            }
        }
    }

    return max;
}

int main()
{
    int N;
    cin >> N;
    vector<int>a;
    for(int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        a.push_back(d);
    }

    int x = maximumGap(a);
    cout << x << endl;
}