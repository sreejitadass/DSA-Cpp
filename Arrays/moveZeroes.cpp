#include <bits/stdc++.h>
using namespace std;

/*
Brute force:
TC: O(2n)   -->     O(n)+O(x)+O(n-x)    [x=no of non-zero elts]
SC: O(x)    -->     To store non zero elements in temp array

Optimal:
TC:
SC:
*/

vector<int> moveZeroesEnd(vector<int> &nums)
{
    // j->1st 0 positon, i-->j+1
    int j = -1, i;
    for (i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return nums;
    else
    {
        for (int i = j + 1; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return nums;
    }
}

int main()
{
    vector<int> nums = {1, 5, 6, 0, 9, 0, 7, 8, 0, 1};
    nums = moveZeroesEnd(nums);
    for (int i : nums)
        cout << i << " ";
    return 0;
}