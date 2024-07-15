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

void dfs(int node, vector<int> adjList[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adjList[node])
    {
        if (!vis[it])
        {
            vis[it] = 1;
            dfs(it, adjList, vis);
        }
    }
}

int countConnectedComponents(int n, vector<int> adjList[])
{
    vector<int> vis(n + 1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adjList, vis);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int m = 8, n = 10;
    vector<int> adjList[n + 1];
    storeGraph(adjList, n, m);
    cout << "Number of connected components = " << countConnectedComponents(n, adjList) << endl;
    return 0;
}