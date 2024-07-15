#include <bits/stdc++.h>
using namespace std;

// Unequal number of positives and negatives
// Use brute force modifcation

vector<int> reArrangeArray(vector<int> &nums)
{
    vector<int> pos, neg;
    int n = nums.size();

    for (int i = 0; i < n; i++)
        nums[i] > 0 ? pos.push_back(nums[i]) : neg.push_back(nums[i]);

    if (pos.size() > neg.size())
    {
        // first alternatively adding equal elements
        for (int i = 0; i < neg.size(); i++)
        {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
        }
        // then append extra positive elements
        int ind = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            nums[ind] = pos[i];
            ind++;
        }
    }
    else
    {
        // first alternatively adding equal elements
        for (int i = 0; i < neg.size(); i++)
        {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
        }
        // then append extra negative elements
        int ind = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            nums[ind] = neg[i];
            ind++;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {-1, 2, 3, 4, -3, 1};
    vector<int> ans = reArrangeArray(nums);
    for (int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}