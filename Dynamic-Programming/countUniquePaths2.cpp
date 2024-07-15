#include <bits/stdc++.h>
using namespace std;

// move from(n-1,m-1) to (0,0)-->UP+LEFT
// obstacle==>-1 cell

// Memoization
int countPaths_memo(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && grid[i][j] == -1)
        return 0; // not count
    if (i == 0 && j == 0)
        return 1; // count
    if (i < 0 || j < 0)
        return 0; // not count
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = countPaths_memo(i - 1, j, grid, dp);
    int left = countPaths_memo(i, j - 1, grid, dp);
    return dp[i][j] = up + left;
}

// Tabulation
int countPaths_tab(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = 0, left = 0;
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            if (grid[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }
    return dp[n - 1][m - 1];
}

// SC Optimized tabulation
int countPaths_tab1(int n, int m, vector<vector<int>> &grid)
{
    vector<int> prevRow(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }
            if (grid[i][j] == -1)
            {
                temp[j] = 0;
                continue;
            }
            int up = 0, left = 0;
            if (i > 0)
                up = prevRow[j];

            if (j > 0)
                left = temp[j - 1];
            temp[j] = up + left;
        }
        prevRow = temp;
    }
    return prevRow[m - 1];
}

int main()
{
    int n = 3, m = 3;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    vector<vector<int>> grid = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    cout << "Number of unique paths (memoization) = " << countPaths_memo(n - 1, m - 1, grid, dp) << endl;
    cout << "Number of unique paths (tabulation) = " << countPaths_tab(n, m, grid, dp) << endl;
    cout << "Number of unique paths (space-optimized) = " << countPaths_tab1(n, m, grid) << endl;
    return 0;
}