#include <bits/stdc++.h>
using namespace std;

int countSubarraysXORK(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1; // storing(s,count)=(0,1) initially

    int xr = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xr ^= nums[i];
        int rem = xr ^ k;

        // if found
        if (mpp.find(rem) != mpp.end())
        {
            cnt += mpp[rem];
        }
        // update count in hashmap
        mpp[xr]++;
    }
    return cnt;
}

int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    cout << "Number of subarrays: " << countSubarraysXORK(nums, 6) << endl;
    return 0;
}