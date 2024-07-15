#include <bits/stdc++.h>
using namespace std;

int longestSubarraysSumK(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    int s = 0, maxLen = 0, len = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        s += nums[i];
        if (s == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = s - k;

        // if found
        if (mpp.find(rem) != mpp.end())
        {
            len = i - mpp[rem];
            maxLen = max(maxLen, len);
        }
        // update index at which prefx sum is occuring in hashmap
        mpp[s] = i;
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {2, 3, 5};
    cout << "Maximum length of subarray: " << longestSubarraysSumK(nums, 5) << endl;
    return 0;
}