#include <bits/stdc++.h>
using namespace std;

// find nearest 1 from every cell
vector<vector<int>> findnearest1(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, (vector<int>(m, 0)));
    vector<vector<int>> output(n, (vector<int>(m, 0)));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    // BFS
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        output[r][c] = d;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, d + 1});
            }
        }
    }
    return output;
}

int main()
{
    vector<vector<int>> grid = {{1, 0, 1}, {1, 1, 0}, {1, 0, 0}};
    vector<vector<int>> output = findnearest1(grid);
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}