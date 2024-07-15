#include <bits/stdc++.h>
using namespace std;

string printLCS(string s1, string s2)
{
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m; i++)
        dp[i][0] = 0;
    for (int j = 0; j < n; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i] == s2[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // extra space
    string lcsStr = "";
    unordered_map<int, int> mpp;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] != 0)
                mpp[dp[i][j]] = j;
        }
    }
    for (auto it = mpp.begin(); it != mpp.end(); ++it)
    {
        int ind = it->second;
        lcsStr += s1[ind - 1];
    }
    reverse(lcsStr.begin(), lcsStr.end());
    return lcsStr;
}

int main()
{
    string s1 = "acd", s2 = "ced";
    string s = printLCS(s1, s2);
    cout << "LCS = " << s << endl;
    return 0;
}