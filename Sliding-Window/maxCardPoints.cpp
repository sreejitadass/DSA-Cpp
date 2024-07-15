#include <bits/stdc++.h>
using namespace std;

int findMaxPoints(vector<int> &nums, int k)
{
    int lsum = 0, rsum = 0, maxsum = 0, r = nums.size() - 1;
    for (int i = 0; i < k; i++) //[6,2,3,4]
    {
        lsum += nums[i];
        maxsum = lsum;
    }
    for (int i = k - 1; i >= 0; i--)
    {
        lsum -= nums[i];
        rsum += nums[r];
        r--;
        maxsum = max(maxsum, (lsum + rsum));
    }
    return maxsum;
}

int main()
{
    vector<int> nums = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    cout << "Maximum points: " << findMaxPoints(nums, 4) << endl;
    return 0;
}