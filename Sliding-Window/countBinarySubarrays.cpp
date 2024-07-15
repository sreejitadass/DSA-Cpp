#include<iostream>
#include<vector>
using namespace std;

int countBinarySubarrays(vector<int> &nums, int goal)
{
    int n = nums.size(), r = 0, l = 0, count = 0, sum = 0;
    if (goal < 0)
        return 0;
    while (r < n)
    {
        sum += nums[r];
        while (sum > goal)
        {
            if (nums[l] == 1)
                sum -= nums[l];
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 0, 0, 1, 1, 0};
    int goal = 2;
    cout << "Count: " << countBinarySubarrays(nums, goal) - countBinarySubarrays(nums, goal - 1) << endl;
    return 0;
}