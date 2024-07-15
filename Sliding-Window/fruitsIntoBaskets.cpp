// maximum length subarray with k distinct integers
// k baskets
#include <bits/stdc++.h>
using namespace std;

int findMaxFruits(vector<int> &nums, int k)
{
    int n = nums.size(), r = 0, l = 0, maxlen = 0, len = 0;
    unordered_map<int, int> mpp;
    while (r < n)
    {
        mpp[nums[r]]++;
        if (mpp.size() > k)
        {
            // shrink window
            mpp[nums[l]]--;
            if (mpp[nums[l]] == 0)
                mpp.erase(nums[l]);
            l++;
        }
        len = r - l + 1;
        maxlen = max(maxlen, len);
        r++;
    }
    return maxlen;
}

int main()
{
    vector<int> nums = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << "Maximum length: " << findMaxFruits(nums, 2) << endl;
    return 0;
}