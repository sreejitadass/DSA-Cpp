#include <bits/stdc++.h>
using namespace std;

// TABULATION
// M-1
int findLPS_tab(int m, int n, string s1, string s2)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

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

// MEMOIZATION
// M-2
int findLPS_rec(int i, int j, string s, vector<vector<int>> &dp)
{
    // 1 char
    if (i == j)
        return 1;
    if (s[i] == s[j] && i + 1 == j)
        return 2;

    // 2 char
    if (s[i] == s[j])
        return findLPS_rec(i + 1, j - 1, s, dp) + 2;

    // If the first and last characters
    // do not match
    return max(findLPS_rec(i, j - 1, s, dp), findLPS_rec(i + 1, j, s, dp));
}

int main()
{
    string s = "cbbd";
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    cout << "LPS length: " << findLPS_rec(0, n - 1, s, dp) << endl;
    return 0;
}