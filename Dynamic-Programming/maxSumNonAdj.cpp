#include <bits/stdc++.h>
using namespace std;

// Memoization
int findMaxSum_memo(int ind, vector<int> &arr, vector<int> &dp)
{
    if (ind == 0)
        return arr[ind]; // pick
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int pick = arr[ind] + findMaxSum_memo(ind - 2, arr, dp);
    int notpick = 0 + findMaxSum_memo(ind - 1, arr, dp);
    return dp[ind] = max(pick, notpick);
}

// SC optimized tabulation
int findMaxSum_tab(int ind, vector<int> &arr)
{
    int prev1 = arr[0];
    int prev2 = 0;
    int curr = 0;
    for (int i = 1; i <= ind; i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int notpick = 0 + prev1;
        curr = max(pick, notpick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    vector<int> arr = {2, 1, 4, 9};
    int n = arr.size();
    vector<int> dp(n, -1);
    cout << "Maximum required sum (memoization) = " << findMaxSum_memo(n - 1, arr, dp) << endl;
    cout << "Maximum required sum (tabulation) = " << findMaxSum_tab(n - 1, arr) << endl;

    return 0;
}