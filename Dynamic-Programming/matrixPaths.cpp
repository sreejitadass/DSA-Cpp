#include <bits/stdc++.h>
using namespace std;

// BOTH VARIABLE POINTS

// Memoization
int findMaxPath_memo(int i, int j, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0) // reached destination
        return grid[0][j];
    if (j < 0 || j >= m) // out of bounds case
        return INT_MIN;
    if (dp[i][j] != -1)
        return dp[i][j];

    int top = INT_MIN, left_dg = INT_MIN, right_dg = INT_MIN;
    top = grid[i][j] + findMaxPath_memo(i - 1, j, m, grid, dp);
    if (i > 0 && j > 0)
        left_dg = grid[i][j] + findMaxPath_memo(i - 1, j - 1, m, grid, dp);
    right_dg = grid[i][j] + findMaxPath_memo(i - 1, j + 1, m, grid, dp);
    return dp[i][j] = max(top, max(left_dg, right_dg));
}

// Tabulation
int findMaxPath_tab(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = grid[0][j];
    }
    int top = INT_MIN, left_dg = INT_MIN, right_dg = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            top = grid[i][j] + dp[i - 1][j];
            left_dg = grid[i][j];
            if (j > 0)
                left_dg += dp[i - 1][j - 1];
            right_dg = grid[i][j];
            if (j < m)
                right_dg += dp[i - 1][j + 1];
            dp[i][j] = max(top, max(left_dg, right_dg));
        }
    }
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
        maxi = max(maxi, dp[n - 1][j]);
    return maxi;
}

// SC optimized solution
int findMaxPath_tab1(int n, int m, vector<vector<int>> &grid)
{
    vector<int> prevRow(m, 0);
    vector<int> temp(m, 0);
    for (int j = 0; j < m; j++)
    {
        prevRow[j] = grid[0][j];
    }
    int top = INT_MIN, left_dg = INT_MIN, right_dg = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            top = grid[i][j] + prevRow[j];
            left_dg = grid[i][j];
            if (j > 0)
                left_dg += prevRow[j - 1];
            right_dg = grid[i][j];
            if (j < m - 1)
                right_dg += prevRow[j + 1];
            temp[j] = max(top, max(left_dg, right_dg));
        }
        prevRow = temp;
    }
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
        maxi = max(maxi, prevRow[j]);
    return maxi;
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 10, 4},
                                {100, 3, 2, 1},
                                {1, 1, 20, 2},
                                {1, 2, 2, 1}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        int pathValue = findMaxPath_memo(n - 1, j, m, grid, dp);
        maxi = max(maxi, pathValue);
    }
    cout << "Maximum path sum (memoization) : " << maxi << endl;
    cout << "Maximum path sum (tabulation) : " << findMaxPath_tab(n, m, grid, dp) << endl;
    cout << "Maximum path sum (space-optimized) : " << findMaxPath_tab1(n, m, grid) << endl;
    return 0;
}