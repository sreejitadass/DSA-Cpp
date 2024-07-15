#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid)
{
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    vis[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int nrow = i + delRow[k];
        int ncol = j + delCol[k];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
        {
            dfs(nrow, ncol, n, m, vis, grid);
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, (vector<int>(m, 0)));
    int cnt = 0;

    // Boundary conditions
    for (int j = 0; j < m; j++)
    {
        // first row
        if (!vis[0][j] && grid[0][j] == 1)
            dfs(0, j, n, m, vis, grid);
        // last row
        if (!vis[n - 1][j] && grid[n - 1][j] == 1)
            dfs(n - 1, j, n, m, vis, grid);
    }
    for (int i = 0; i < n; i++)
    {
        // first column
        if (!vis[i][0] && grid[i][0] == 1)
            dfs(i, 0, n, m, vis, grid);
        // last column
        if (!vis[i][m - 1] && grid[i][m - 1] == 1)
            dfs(i, m - 1, n, m, vis, grid);
    }

    // Within boundary conditions
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << "Number of enclaves: " << numEnclaves(grid) << endl;
    return 0;
}