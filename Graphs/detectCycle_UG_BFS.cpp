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

bool bfs(int s, vector<int> adjList[], vector<int> &visited)
{
    queue<pair<int, int>> q;
    q.push({s, -1}); // source,parent
    visited[s] = 1;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adjList[node])
        {
            // if not visited then perform bfs
            if (!visited[it])
            {
                visited[it] = 1;
                q.push({it, node});
            }
            // if there is a back edge, visited
            else if (it != parent)
                return true;
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adjList[])
{
    vector<int> visited(n + 1, 0);
    // connected components graph
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (bfs(i, adjList, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    int m = 7, n = 7;
    vector<int> adjList[n + 1];
    storeGraph(adjList, m, n);
    if (isCycle(n, adjList))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle detected" << endl;
    return 0;
}