#include <bits/stdc++.h>
using namespace std;

// TABULATION
int findLCS_tab(int m, int n, string s1, string s2)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int ans = -1e9;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

// SC-optimized
int findLCS_tab1(int m, int n, string s1, string s2)
{
    vector<int> prevRow(n + 1, 0);
    vector<int> temp(n + 1, 0);
    int ans = -1e9;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                temp[j] = 1 + prevRow[j - 1];
                ans = max(ans, temp[j]);
            }
            else
                temp[j] = 0;
        }
        prevRow = temp;
    }
    return ans;
}

int main()
{
    string s1 = "abcde", s2 = "bcdfea";
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int maxi = -1e9;
    cout << "LCS length: (tabulation) " << findLCS_tab(m, n, s1, s2) << endl;
    cout << "LCS length: (space optimized) " << findLCS_tab1(m, n, s1, s2) << endl;
    return 0;
}