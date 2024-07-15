#include <bits/stdc++.h>
using namespace std;

int minTimeRotten(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, (vector<int>(m, 0)));
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
        }
    }

    int tm = 0;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    // BFS
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
            {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
            }
        }
    }
    return tm;
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 1}, {1, 1, 0}, {0, 0, 1}};
    cout << "The min time is: " << minTimeRotten(grid) << endl;
    return 0;
}