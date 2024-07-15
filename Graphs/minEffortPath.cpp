#include <bits/stdc++.h>
using namespace std;

int findMinEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size(), m = heights[0].size();
    vector<vector<int>> effort(n, (vector<int>(m, 1e9)));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    effort[0][0] = 0;

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while (!pq.empty())
    {
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        int d = pq.top().first;
        pq.pop();

        if (r == n - 1 && c == m - 1)
            return d;

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                int newD = max(abs(heights[r][c] - heights[nrow][ncol]), d);
                if (newD < effort[nrow][ncol])
                {
                    effort[nrow][ncol] = newD;
                    pq.push({newD, {nrow, ncol}});
                }
            }
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << "Path with minimum effort: " << findMinEffortPath(heights) << endl;
    return 0;
}