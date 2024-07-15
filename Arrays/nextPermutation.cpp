#include <bits/stdc++.h>
using namespace std;

vector<int> generateNextPermutation(vector<int> &nums)
{
    // 1.Find the breaking point
    int n = nums.size();
    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end()); // if last permutation is given, reverse it
        return nums;
    }
    else
    {
        // 2.Swap with next greater element
        for (int i = n - 1; i >= ind; i--)
        {
            if (nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        // 3.Reverse/Sort remaining part
        reverse(nums.begin() + ind + 1, nums.end());
        return nums;
    }
}

int main()
{
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = generateNextPermutation(nums);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
}