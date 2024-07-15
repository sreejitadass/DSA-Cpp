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

bool dfs(int node, int color, vector<int> &colorArr, vector<int> adjList[])
{
    colorArr[node] = color;
    for (auto it : adjList[node])
    {
        if (colorArr[it] == -1)
        {
            if (dfs(it, !color, colorArr, adjList) == false)
                return false;
        }
        else if (colorArr[it] == color)
            return false;
    }
    return true;
}

bool isBipartite(int n, vector<int> &colorArr, vector<int> adjList[])
{
    // connected components graph
    for (int i = 1; i <= n; i++)
    {
        if (colorArr[i] == -1)
        {
            if (dfs(i, 0, colorArr, adjList) == false)
                return false;
        }
    }
    return true;
}

int main()
{
    int n = 9, m = 9;
    vector<int> adjList[n + 1];
    storeGraph(adjList, n, m);
    vector<int> colorArr(n + 1, -1);
    if (isBipartite(n, colorArr, adjList))
        cout << "Bipartite" << endl;
    else
        cout << "Not bipartite" << endl;
    return 0;
}