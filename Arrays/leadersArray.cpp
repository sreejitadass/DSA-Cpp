#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;
    int max = nums[n - 1];
    temp.push_back(nums[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > max)
        {
            temp.push_back(nums[i]);
            max = nums[i];
        }
    }
    return temp;
}

int main()
{
    vector<int> nums = {10, 22, 12, 3, 0, 6};
    vector<int> temp = findLeaders(nums);
    for (int i = temp.size() - 1; i >= 0; i--)
        cout << temp[i] << " ";
    cout << endl;
    return 0;
}