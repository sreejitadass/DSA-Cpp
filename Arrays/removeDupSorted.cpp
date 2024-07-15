#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();
    for (int j = 1; j < n; j++)
    {
        if (nums[i] != nums[j])
        {
            nums[(i + 1)] = nums[j];
            i++;
        }
    }
    return i + 1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    cout << "Number of unique elements: " << removeDuplicates(nums) << endl;
    return 0;
}