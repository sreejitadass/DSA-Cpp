#include <bits/stdc++.h>
using namespace std;

// Memoization
int findMinimumEnergy_memo(int n, vector<int> &arr, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int right = INT_MAX;
    int left = findMinimumEnergy_memo(n - 1, arr, dp) + abs(arr[n] - arr[n - 1]);
    if (n > 1)
        right = findMinimumEnergy_memo(n - 2, arr, dp) + abs(arr[n] - arr[n - 2]);
    return dp[n] = min(left, right);
}

// SC optimized tabulation
int findMinimumEnergy_tab(int n, vector<int> &arr)
{
    int prev1 = 0, prev2 = 0, curr = 0;
    for (int i = 1; i < n; i++)
    {
        int left = prev1 + abs(arr[n] - arr[n - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(arr[n] - arr[n - 2]);
        curr = min(left, right);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main()
{
    int n = 6;
    vector<int> dp(n, -1);
    vector<int> arr = {30, 10, 60, 10, 60, 50};
    cout << "Minimum energy required: " << findMinimumEnergy_tab(n - 1, arr) << endl;
    return 0;
}