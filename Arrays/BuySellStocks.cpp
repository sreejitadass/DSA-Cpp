#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &nums)
{
    int sell, buy = nums[0], profit = 0, cost;
    for (int i = 0; i < nums.size(); i++)
    {
        sell = nums[i];

        cost = sell - buy;
        profit = max(profit, cost);
        buy = min(buy, nums[i]);
    }
    return profit;

    // int buy = nums[0], profit = 0, maxProfit = 0;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] < buy)
    //         buy = nums[i];

    //     profit = nums[i] - buy;
    //     maxProfit = max(profit, maxProfit);
    // }
    // return maxProfit;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit: " << maxProfit(nums) << endl;

    return 0;
}