#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
bool ifSubsetSumTarget_memo(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
        return arr[ind] == target;
    if (target == 0)
        return true;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool take = false;
    if (target >= arr[ind])
        take = ifSubsetSumTarget_memo(ind - 1, target - arr[ind], arr, dp);
    bool notTake = ifSubsetSumTarget_memo(ind - 1, target, arr, dp);
    return dp[ind][target] = take || notTake;
}

// TABULATION
bool ifSubsetSumTarget_tab(int n, int target, vector<int> &arr, vector<vector<bool>> &dp)
{
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= target)
        dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool take = false;
            if (target >= arr[i])
                take = dp[i - 1][j - arr[i]];
            bool notTake = dp[i - 1][j];
            dp[i][j] = take || notTake;
        }
    }
    return dp[n - 1][target];
}

// SC OPTIMIZED TABULATION
bool ifSubsetSumTarget_tab1(int n, int target, vector<int> &arr)
{
    vector<bool> prevRow(target + 1, false);
    prevRow[0] = true;
    if (arr[0] <= target)
        prevRow[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        vector<bool> temp(target + 1, false);
        for (int j = 1; j <= target; j++)
        {
            bool take = false;
            if (target >= arr[i])
                take = prevRow[j - arr[i]];
            bool notTake = prevRow[j];
            temp[j] = take || notTake;
        }
        prevRow = temp;
    }
    return prevRow[target];
}

int main()
{
    vector<int> arr = {2, 3, 1, 1};
    int n = arr.size();
    int target = 4;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    vector<vector<bool>> dp1(n, vector<bool>(target + 1, -1));
    if (ifSubsetSumTarget_memo(n - 1, target, arr, dp))
        cout << "Subset sum is equal to target (memoization)" << endl;
    if (ifSubsetSumTarget_tab(n, target, arr, dp1))
        cout << "Subset sum is equal to target (tabulation)" << endl;
    if (ifSubsetSumTarget_tab1(n, target, arr))
        cout << "Subset sum is equal to target (space-optimized)" << endl;
    return 0;
}