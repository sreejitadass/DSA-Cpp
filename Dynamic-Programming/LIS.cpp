#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
int findLIS_memo(int ind, int prev, int n, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    int notTake = 0 + findLIS_memo(ind + 1, prev, n, arr, dp);
    int take = 0;
    if (prev == -1 || arr[ind] > arr[prev])
        take = 1 + findLIS_memo(ind + 1, ind, n, arr, dp);
    return dp[ind][prev + 1] = max(notTake, take);
}

// TABULATION
int findLIS_tab(int n, vector<int> &arr)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int notTake = 0 + dp[ind + 1][prev + 1];
            int take = 0;
            if (prev == -1 || arr[ind] > arr[prev])
                take = 1 + dp[ind + 1][ind + 1];
            dp[ind][prev + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}

// with lcs
//  int findLCS_tab1(int n, vector<int> &s1, vector<int> &s2)
//  {
//      vector<int> prevRow(n + 1, 0);
//      vector<int> temp(n + 1, 0);
//      if (s1[0] == s1[n - 1])
//          return 1;
//      for (int i = 1; i <= n; i++)
//      {
//          for (int j = 1; j <= n; j++)
//          {
//              if (s1[i - 1] == s2[j - 1])
//                  temp[j] = 1 + prevRow[j - 1];
//              else
//                  temp[j] = 0 + max(prevRow[j], temp[j - 1]);
//          }
//          prevRow = temp;
//      }
//      return prevRow[n];
//  }

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Length of LIS (memoization): " << findLIS_memo(0, -1, n, arr, dp) << endl;
    cout << "Length of LIS (tabulation): " << findLIS_tab(n, arr) << endl;

    return 0;
}