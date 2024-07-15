#include <bits/stdc++.h>
using namespace std;

int countNiceSubarrays(vector<int> &nums, int goal)
{
    int n = nums.size(), r = 0, l = 0, count = 0, sum = 0;
    if (goal < 0)
        return 0;
    while (r < n)
    {
        sum += (nums[r] % 2);
        while (sum > goal)
        {
            if ((nums[l] % 2) == 1)
                sum -= (nums[l] % 2);
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    int goal = 3;
    cout << "Count: " << countNiceSubarrays(nums, goal) - countNiceSubarrays(nums, goal - 1) << endl;
    return 0;
}