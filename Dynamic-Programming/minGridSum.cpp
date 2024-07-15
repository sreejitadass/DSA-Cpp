#include <bits/stdc++.h>
using namespace std;

// Memoization
int minPath_memo(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0]; // count
    if (i < 0 || j < 0)
        return INT_MAX; // not count
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = INT_MAX, left = INT_MAX;
    if (i > 0)
        up = grid[i][j] + minPath_memo(i - 1, j, grid, dp);
    if (j > 0)
        left = grid[i][j] + minPath_memo(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}

// Tabulation
int minPath_tab(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = INT_MAX, left = INT_MAX;
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[0][0];
                continue;
            }
            if (i > 0)
                up = grid[i][j] + dp[i - 1][j];
            if (j > 0)
                left = grid[i][j] + dp[i][j - 1];
            dp[i][j] = min(up, left);
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n - 1][m - 1];
}

// SC Optimized tabulation
int minPath_tab1(int n, int m, vector<vector<int>> &grid)
{
    vector<int> prevRow(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = grid[0][0];
                continue;
            }
            int up = INT_MAX, left = INT_MAX;
            if (i > 0)
                up = grid[i][j] + prevRow[j];

            if (j > 0)
                left = grid[i][j] + temp[j - 1];
            temp[j] = min(up, left);
        }
        prevRow = temp;
    }
    return prevRow[m - 1];
}

int main()
{
    vector<vector<int>> grid = {{5, 9, 6}, {11, 5, 2}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << "Minimum path sum (memoization) = " << minPath_memo(n - 1, m - 1, grid, dp) << endl;
    cout << "Minimum path sum (tabulation) = " << minPath_tab(n, m, grid, dp) << endl;
    cout << "Minimum path sum (space-optimized) = " << minPath_tab1(n, m, grid) << endl;
    return 0;
}
