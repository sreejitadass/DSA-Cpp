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

void dfs(int node, vector<int> &visited, stack<int> &s, vector<int> adjList[])
{
    visited[node] = 1;
    for (auto it : adjList[node])
    {
        if (!visited[it])
            dfs(it, visited, s, adjList);
    }
    s.push(node);
}

vector<int> findTopoSort(int n, vector<int> adjList[])
{
    vector<int> ans;
    vector<int> visited(n, 0);
    stack<int> s;
    for (int i = 0; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, s, adjList);
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    int n = 6, m = 6;
    vector<int> adjList[n];
    storeGraph(adjList, n, m);
    vector<int> ans = findTopoSort(n, adjList);
    cout << "\nTopological sort = ";
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}