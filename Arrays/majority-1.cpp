//>n/3

#include <bits/stdc++.h>
using namespace std;

// modification of n/2 algo
vector<int> findMajority(vector<int> &nums)
{
    int cnt1 = 0, cnt2 = 0, el1 = 0, el2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && el2 != nums[i])
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && el1 != nums[i])
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i])
            cnt1++;
        else if (el2 == nums[i])
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    int mini = (int(nums.size()) / 3) + 1;
    vector<int> ls;
    for (int i = 0; i < nums.size(); i++)
    {
        if (el1 == nums[i])
            cnt1++;
        if (el2 == nums[i])
            cnt2++;
    }
    if (cnt1 >= mini)
        ls.push_back(el1);
    if (cnt2 >= mini)
        ls.push_back(el2);

    return ls;
}

int main()
{
    vector<int> nums = {2, 1, 1, 3, 1, 4, 5, 6, 3};
    vector<int> ans = findMajority(nums);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}