#include <bits/stdc++.h>
using namespace std;

// Memoization
int findMinimumEnergy_memo(int n, int k, vector<int> &arr, vector<int> &dp)
{
    int minSteps = INT_MAX;
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int jump = findMinimumEnergy_memo(n - i, k, arr, dp) + abs(arr[n] - arr[n - i]);
            minSteps = min(minSteps, jump);
        }
    }
    return dp[n] = minSteps;
}

int findMinimumEnergy_tab(int n, int k, vector<int> &arr)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                dp[i] = min(dp[i], jump);
            }
        }
    }
    return dp[n - 1];
}

int main()
{
    int n = 6;
    vector<int> arr = {30, 10, 60, 10, 60, 50};
    int k = 3;

    // Using Memoization
    vector<int> dp_memo(n, -1);
    cout << "Minimum energy required (Memoization): " << findMinimumEnergy_memo(n - 1, k, arr, dp_memo) << endl;

    // Using Tabulation
    cout << "Minimum energy required (Tabulation): " << findMinimumEnergy_tab(n, k, arr) << endl;

    return 0;
}
