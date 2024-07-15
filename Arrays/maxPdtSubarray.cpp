#include <bits/stdc++.h>
using namespace std;

int maxPdt(vector<int> &nums)
{
    int pre = 1, suff = 1, ans = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;

        pre *= nums[i];          // front
        suff *= nums[n - i - 1]; // back
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main()
{
    vector<int> nums = {2,
                        3,
                        -2,
                        0,
                        4,
                        1, 0, 3, 6};
    cout << "Maximum product: " << maxPdt(nums) << endl;
    return 0;
}