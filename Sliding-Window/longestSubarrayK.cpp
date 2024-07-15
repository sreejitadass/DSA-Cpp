#include <bits/stdc++.h>
using namespace std;

int findLongestSubarray(vector<int> &nums, int k)
{
    int n = nums.size(), r = 0, l = 0, sum = 0, maxlen = 0;
    while (r < n)
    {
        sum += nums[r];
        while (sum > k && l <= r)
        {
            sum -= nums[l];
            l++;
        }
        if (sum == k)
            maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int main()
{
    vector<int> nums = {2, 3, 5, 1, 9};
    int k = 10;
    cout << "Length of longest subarray: " << findLongestSubarray(nums, k) << endl;
    return 0;
}