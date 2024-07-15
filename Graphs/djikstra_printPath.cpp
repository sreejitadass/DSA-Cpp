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

vector<int> printShortestPath(int src, int dest, int n, vector<pair<int, int>> adjList[])
{
    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1);
    // each node is its own parent
    parent[0] = 0;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
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
                parent[v] = u;
            }
        }
    }

    vector<int> ans;
    int node = dest;
    while (parent[node] != node)
    {
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(src);
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int n = 5, m = 6;
    int src = 1, dest = n;
    vector<vector<int>> edges = {{1, 4, 1}, {1, 2, 2}, {2, 5, 5}, {5, 3, 1}, {3, 4, 3}, {{3, 2, 4}}};
    vector<pair<int, int>> adjList[n + 1];
    storeGraph(n, m, edges, adjList);
    vector<int> ans = printShortestPath(src, dest, n, adjList);
    cout << "Shortest path: ";
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}