#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
int countSubsets_memo(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (ind == 0)
        return (arr[ind] == target) ? 1 : 0;
    if (dp[ind][target] != 0)
        return dp[ind][target];
    int take = 0;
    if (arr[ind] <= target)
        take = countSubsets_memo(ind - 1, target - arr[ind], arr, dp);
    int notTake = countSubsets_memo(ind - 1, target, arr, dp);
    return dp[ind][target] = take + notTake;
}

// TABULATION
int countSubsets_tab(int n, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (arr[0] <= target)
        dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            int take = 0;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            int notTake = dp[i - 1][j];
            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][target];
}

// SC OPTIMIZED TABULATION
int countSubsets_tab1(int n, int target, vector<int> &arr)
{
    vector<int> prevRow(target + 1, 0);
    prevRow[0] = 1;
    if (arr[0] <= target)
        prevRow[arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        vector<int> temp(target + 1, 0);
        temp[0] = 1;
        for (int j = 1; j <= target; j++)
        {
            int take = 0;
            if (arr[i] <= j)
                take = prevRow[j - arr[i]];
            int notTake = prevRow[j];
            temp[j] = take + notTake;
        }
        prevRow = temp;
    }
    return prevRow[target];
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int target = 3;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    cout << "The number of required subsets (memoization): " << countSubsets_memo(n - 1, target, arr, dp) << endl;
    cout << "The number of required subsets (tabulation): " << countSubsets_tab(n, target, arr, dp) << endl;
    cout << "The number of required subsets (space-optimized): " << countSubsets_tab1(n, target, arr) << endl;
    return 0;
}