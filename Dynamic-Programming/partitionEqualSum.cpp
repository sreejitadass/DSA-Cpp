#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
bool canPartition_memo(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
        return arr[ind] == target;
    if (target == 0)
        return true;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool take = false;
    if (target >= arr[ind])
        take = canPartition_memo(ind - 1, target - arr[ind], arr, dp);
    bool notTake = canPartition_memo(ind - 1, target, arr, dp);
    return dp[ind][target] = take || notTake;
}

// SC OPTIMIZED TABULATION
bool canPartition_tab1(int n, int target, vector<int> &arr)
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

bool canPartition(vector<int> &arr)
{
    int n = arr.size();
    int S = 0;
    for (int i : arr)
        S += i;
    if (S % 2)
        return false;
    int target = S / 2;
    return canPartition_tab1(n, target, arr);
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    if (canPartition(arr))
        cout << "Partition possible (space-optimized)" << endl;
}