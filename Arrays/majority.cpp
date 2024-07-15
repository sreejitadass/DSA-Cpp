//>n/2

#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(vector<int> &nums)
{
    // Moore's voting algo
    int cnt = 0, el = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = nums[i];
        }
        else if (el == nums[i])
            cnt++;
        else
            cnt--;
    }

    // last check for majority element(if it might not exist)
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == el)
            cnt1++;
    }
    if (cnt1 > n / 2)
        return el;
    return -1;
}

int main()
{
    vector<int> nums = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
    cout << "Majority element is: " << findMajorityElement(nums) << endl;
    return 0;
}
