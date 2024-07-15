#include <bits/stdc++.h>
using namespace std;

pair<int, int> findSingleNumber(vector<int> &nums)
{
    long long XORall = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        XORall ^= nums[i];
    }
    long long rightmost = ((XORall & (XORall - 1)) ^ XORall); // differing bit position
    long long b1 = 0, b2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (rightmost & nums[i]) // 1
            b1 ^= nums[i];
        else // 0
            b2 ^= nums[i];
    }
    return {b1, b2};
}

int main()
{
    vector<int> nums = {2, 4, 2, 14, 3, 3, 7, 7};
    pair<int, int> result = findSingleNumber(nums);
    cout << "Single numbers are: " << result.first << " " << result.second << endl;
    return 0;
}