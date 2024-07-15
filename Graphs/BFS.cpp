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

vector<int> findBFS(int s, int n, vector<int> adjList[])
{
    vector<int> ans;
    queue<int> q;
    vector<int> vis(n + 1, 0);
    // for starting node
    q.push(s);
    vis[s] = 1;

    // for others
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adjList[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;
}

int main()
{
    int m = 8, n = 8, s = 1;
    vector<int> adjList[n + 1];
    storeGraph(adjList, n, m);
    vector<int> ans = findBFS(s, n, adjList);
    cout << "BFS: ";
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}