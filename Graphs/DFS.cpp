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

void dfs(int node, vector<int> adjList[], vector<int> &vis, vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto it : adjList[node])
    {
        if (!vis[it])
        {
            vis[it] = 1;
            dfs(it, adjList, vis, ans);
        }
    }
}

vector<int> findDFS(int s, int n, vector<int> adjList[])
{
    vector<int> vis(n + 1, 0);
    vector<int> ans;
    dfs(s, adjList, vis, ans);
    return ans;
}

int main()
{
    int m = 8, n = 8, s = 1;
    vector<int> adjList[n + 1];
    storeGraph(adjList, n, m);
    vector<int> ans = findDFS(s, n, adjList);
    cout << "DFS: ";
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}