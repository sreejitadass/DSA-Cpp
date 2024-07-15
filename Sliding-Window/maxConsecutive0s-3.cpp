#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutive0sK(vector<int> &nums, int k)
{
    int l = 0, r = 0, n = nums.size(), maxLen = 0, len = 0, zeroes = 0;
    while (r < n)
    {
        if (nums[r] == 0)
            zeroes++;

        while (zeroes > k)
        {
            if (nums[l] == 0)
                zeroes--;
            l++;
        }

        len = r - l + 1;
        maxLen = max(maxLen, len);
        r++;
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << "Maximum zeroes: " << findMaxConsecutive0sK(nums, 2) << endl;
    return 0;
}