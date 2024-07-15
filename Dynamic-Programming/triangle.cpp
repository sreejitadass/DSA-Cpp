#include <bits/stdc++.h>
using namespace std;

// FIXED STARTING POINT,VARIABLE ENDING POINT

// Memoization
int findMinSum_memo(int i, int j, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    // base case
    if (i == n - 1)
        return grid[n - 1][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = INT_MAX, diagonal = INT_MAX;
    down = grid[i][j] + findMinSum_memo(i + 1, j, n, grid, dp);
    diagonal = grid[i][j] + findMinSum_memo(i + 1, j + 1, n, grid, dp);
    return dp[i][j] = min(down, diagonal);
}

// Tabulation
int findMinSum_tab(int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    // base case
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = grid[n - 1][j];
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = grid[i][j] + dp[i + 1][j];
            int diagonal = grid[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

// SC optimized tabulation
int findMinSum_tab1(int n, vector<vector<int>> &grid)
{
    vector<int> frontRow(n, 0);
    for (int j = 0; j < n; j++)
        frontRow[j] = grid[n - 1][j];
    int down = INT_MAX, diagonal = INT_MAX;
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> temp(n, 0);
        for (int j = i; j >= 0; j--)
        {
            down = grid[i][j] + frontRow[j];
            diagonal = grid[i][j] + frontRow[j + 1];
            temp[j] = min(down, diagonal);
        }
        frontRow = temp;
    }
    return frontRow[0];
}

int main()
{
    vector<vector<int>> grid = {{1}, {2, 3}};
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Minimum path sum (memoization) = " << findMinSum_memo(0, 0, n, grid, dp) << endl;
    cout << "Minimum path sum (tabulation) = " << findMinSum_tab(n, grid, dp) << endl;
    cout << "Minimum path sum (space-optimized) = " << findMinSum_tab1(n, grid) << endl;
    return 0;
}