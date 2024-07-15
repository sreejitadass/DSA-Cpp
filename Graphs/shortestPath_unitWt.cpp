#include <bits/stdc++.h>
using namespace std;

void storeGraph(vector<int> adjList[], int n, int m)
{
    int u, v;
    cout << "Enter:  " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cout << "Graph stored" << endl;
}

vector<int> findShortestPath(int src, int n, vector<int> adjList[])
{
    vector<int> dist(n, 1e9);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adjList[node])
        {
            // shortest path
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = 1 + dist[node];
                q.push(it);
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
    int src = 0, n = 9, m = 11;
    vector<int> adjList[n];
    storeGraph(adjList, n, m);
    vector<int> ans = findShortestPath(src, n, adjList);
    cout << "Shortest distances: ";
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}