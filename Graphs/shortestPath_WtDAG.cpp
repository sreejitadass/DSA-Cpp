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
    }
    cout << "Graph stored" << endl;
}

void findTopoSort(int node, int n, vector<int> &vis, stack<int> &s, vector<pair<int, int>> adjList[])
{
    vis[node] = 1;
    for (auto it : adjList[node])
    {
        int v = it.first;
        if (!vis[v])
        {
            findTopoSort(v, n, vis, s, adjList);
        }
    }
    s.push(node);
}

vector<int> findShortestDistance(int n, vector<pair<int, int>> adjList[])
{
    vector<int> dist(n, 1e9);
    vector<int> vis(n, 0);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            findTopoSort(i, n, vis, s, adjList);
    }
    dist[0] = 0;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        for (auto it : adjList[u])
        {
            int v = it.first;
            int w = it.second;
            if (w + dist[u] < dist[v])
            {
                dist[v] = w + dist[u];
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
    int n = 6, m = 7;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    vector<pair<int, int>> adjList[n];
    storeGraph(n, m, edges, adjList);
    vector<int> ans = findShortestDistance(n, adjList);
    cout << "Shortest distances: ";
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
