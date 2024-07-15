#include <bits/stdc++.h>
using namespace std;

void floodFillMatrix(vector<vector<int>> &grid, int newColor, int sr, int sc)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, (vector<int>(m, 0)));
    int initialColor = grid[sr][sc];
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = 1;
    grid[sr][sc] = newColor;

    if (initialColor == newColor)
        return;

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == initialColor && !vis[nrow][ncol])
            {
                q.push({nrow, ncol});
                grid[nrow][ncol] = newColor;
                vis[nrow][ncol] = 1;
            }
        }
    }
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1}, {2, 2, 0}, {2, 2, 2}};
    cout << "Original grid: " << endl;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    floodFillMatrix(grid, 3, 2, 0);
    cout << "Changed grid: " << endl;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}