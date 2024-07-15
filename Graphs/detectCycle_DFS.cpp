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
    }
    cout << "Graph stored" << endl;
}

bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adjList[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adjList[node])
    {
        if (!vis[it])
        {
            if (dfs(it, vis, pathVis, adjList) == true)
                return true;
        }
        else if (vis[it] && pathVis[it])
            return true;
    }
    pathVis[node] = 0;
    return false;
}

bool isCycle(vector<int> adjList[], int n)
{
    vector<int> vis(n + 1, 0);
    vector<int> pathVis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, pathVis, adjList) == true)
                return true;
        }
    }
    return false;
}

int main()
{
    int n = 10, m = 11;
    vector<int> adjList[n + 1];
    storeGraph(adjList, n, m);
    if (isCycle(adjList, n))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle detected" << endl;
    return 0;
}
