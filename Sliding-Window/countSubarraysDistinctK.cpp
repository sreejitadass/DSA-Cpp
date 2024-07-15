#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> &nums, int k)
{
    int n = nums.size(), r = 0, l = 0, cnt = 0;
    unordered_map<int, int> mpp; //(number,frequency)
    while (r < n)
    {
        mpp[nums[r]]++;
        while (mpp.size() > k)
        {
            mpp[nums[l]]--;
            if (mpp[nums[l]] == 0)
                mpp.erase(nums[l]);
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Number of subarrays: " << countSubarrays(nums, k) - countSubarrays(nums, k - 1) << endl;
    return 0;
}