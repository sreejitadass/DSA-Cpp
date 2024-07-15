#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutive1s(vector<int> &nums)
{
    int cnt = 0;
    int max1 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            cnt = 0;
        }
        else
        {
            cnt++;
            if (cnt > max1)
                max1 = cnt;
        }
    }
    return max1;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1};
    cout << "Max consecutive number of 1s: " << findMaxConsecutive1s(nums) << endl;
    return 0;
}