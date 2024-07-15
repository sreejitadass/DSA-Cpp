#include <bits/stdc++.h>
using namespace std;

// logic+other 3 approaches in copy

// CONCEPT OF BUCKETS
int findSingleNumber(vector<int> &nums)
{
    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // add to ones/twos only if the other one is 0
        ones = (ones ^ nums[i]) & (~twos);
        twos = (twos ^ nums[i]) & (~ones);
    }
    return ones;
}

int main()
{
    vector<int> nums = {2, 2, 2, 3, 4, 4, 4, 5, 5, 5};
    cout << "Single number: " << findSingleNumber(nums) << endl;
    return 0;
}