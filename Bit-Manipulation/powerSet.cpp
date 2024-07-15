#include <bits/stdc++.h>
using namespace std;

bool checkIfSetBit(int N, int i)
{
    return ((N & (1 << i)) != 0);
}

vector<vector<int>> findPowerSet(vector<int> &nums)
{
    int n = 1 << (nums.size()); // 2 to the power n
    vector<vector<int>> ans;

    for (int num = 0; num < n; num++)
    {
        vector<int> list;
        for (int i = 0; i < nums.size(); i++)
        {
            if (checkIfSetBit(num, i))
            {
                list.push_back(nums[i]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = findPowerSet(nums);
    cout << "Power set: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}