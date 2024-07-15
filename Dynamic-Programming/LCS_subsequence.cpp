#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
int findLCS_memo(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != 0)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + findLCS_memo(i - 1, j - 1, s1, s2, dp);
    else
        return dp[i][j] = 0 + max(findLCS_memo(i - 1, j, s1, s2, dp), findLCS_memo(i, j - 1, s1, s2, dp));
}

// TABULATION
int findLCS_tab(int m, int n, string s1, string s2)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    // base cases
    for (int i = 0; i < m; i++)
        dp[i][0] = 0;
    for (int j = 0; j < n; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

// SC-optimized
int findLCS_tab1(int m, int n, string s1, string s2)
{
    vector<int> prevRow(n + 1, 0);
    vector<int> temp(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                temp[j] = 1 + prevRow[j - 1];
            else
                temp[j] = 0 + max(prevRow[j], temp[j - 1]);
        }
        prevRow = temp;
    }
    return prevRow[n];
}

int main()
{
    string s1 = "cbbd", s2 = "dbbc";
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    cout << "LCS length: (memoization) " << findLCS_memo(m - 1, n - 1, s1, s2, dp) << endl;
    cout << "LCS length: (tabulation) " << findLCS_tab(m, n, s1, s2) << endl;
    cout << "LCS length: (space optimized) " << findLCS_tab1(m, n, s1, s2) << endl;
    return 0;
}