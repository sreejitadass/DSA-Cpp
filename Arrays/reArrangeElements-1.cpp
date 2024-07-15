#include <bits/stdc++.h>
using namespace std;

// Equal number of positives and negatives

// positives in even,negatives in odd
vector<int> reArrangeArray(vector<int> &nums)
{
    vector<int> ans(nums.size());
    int k = 1, j = 0; // k-->negative index,j-->positive index
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            ans[k] = nums[i];
            k += 2;
        }
        else
        {
            ans[j] = nums[i];
            j += 2;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> ans = reArrangeArray(nums);
    for (int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}
