#include <bits/stdc++.h>
using namespace std;

void storeGraph(int n, int m)
{
    vector<int> adjList[n + 1];
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

int main()
{
    int m = 6, n = 5;
    storeGraph(n, m);
    return 0;
}