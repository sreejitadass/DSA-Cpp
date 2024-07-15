#include <bits/stdc++.h>
using namespace std;

void storeGraph(int n, int m, vector<vector<int>> &edges, vector<pair<int, int>> adjList[])
{
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];
        adjList[u].push_back({v, w}); // start->{end,weight}
        adjList[v].push_back({u, w});
    }
    cout << "Graph stored" << endl;
}

vector<int> findShortestDistance(int src, int n, vector<pair<int, int>> adjList[])
{
    vector<int> dist(n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); //{dist,node}
    dist[src] = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int u = it.second;
        // neighbouring nodes
        for (auto it : adjList[u])
        {
            int v = it.first;
            int w = it.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = w + dist[u];
                pq.push({dist[v], v});
            }
        }
    }
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != 1e9)
            ans[i] = dist[i];
    }
    return ans;
}

int main()
{
    int n = 6, m = 8;
    vector<pair<int, int>> adjList[n];
    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 4}, {1, 2, 2}, {2, 3, 3}, {2, 5, 6}, {2, 4, 1}, {3, 5, 2}, {4, 5, 3}};
    storeGraph(n, m, edges, adjList);
    vector<int> ans = findShortestDistance(0, n, adjList);
    cout << "Shortest distances: ";
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}