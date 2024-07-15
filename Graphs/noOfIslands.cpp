#include <bits/stdc++.h>
using namespace std;

void bfs(int r, int c, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    vis[r][c] = 1;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int nrow = i + r;
                int ncol = j + c;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int numIslands(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, (vector<int>(m, 0)));
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                cnt++;
                bfs(i, j, n, m, grid, vis);
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {1, 1, 0, 1}};
    cout << "Number of islands: " << numIslands(grid) << endl;
    return 0;
}