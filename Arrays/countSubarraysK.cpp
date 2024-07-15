#include <bits/stdc++.h>
using namespace std;

int countSubarraysSumK(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1; // storing(s,count)=(0,1) initially

    int s = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        s += nums[i];
        int rem = s - k;

        // if found
        if (mpp.find(rem) != mpp.end())
        {
            cnt += mpp[rem];
        }
        // update count in hashmap
        mpp[s]++;
    }
    return cnt;
}

int main()
{
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << "Number of subarrays: " << countSubarraysSumK(nums, 3) << endl;
    return 0;
}