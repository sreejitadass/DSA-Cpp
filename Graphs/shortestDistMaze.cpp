#include <bits/stdc++.h>
using namespace std;

int findShortestDistance(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int src_row = 0, src_col = 1, dest_row = 2, dest_col = 2;
    vector<vector<int>> dist(n, (vector<int>(m, 1e9)));

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src_row, src_col}});
    dist[src_row][src_col] = 0;

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    if (grid[src_row][src_col] == 0 || grid[dest_row][dest_col] == 0)
        return -1;

    while (!q.empty())
    {
        int r = q.front().second.first;
        int c = q.front().second.second;
        int d = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && 1 + d < dist[nrow][ncol])
            {
                dist[nrow][ncol] = (1 + d);
                q.push({dist[nrow][ncol], {nrow, ncol}});
                if (nrow == dest_row && ncol == dest_col)
                    return dist[nrow][ncol];
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}, {1, 0, 0, 0}};
    cout << "Min path: " << findShortestDistance(grid) << endl;
    return 0;
}