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

bool isCyclic(int n, vector<int> adjList[])
{
    vector<int> indegree(n, 0);
    int cnt = 0;

    // finding indegree
    for (int i = 0; i < n; i++)
    {
        for (auto it : adjList[i])
        {
            indegree[it]++;
        }
    }

    // if indegree=0, push in queue
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // remove edges from those nodes and reduce indegree and repeat
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for (auto it : adjList[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return !(cnt == n);
}

int main()
{
    int n = 4, m = 4;
    vector<int> adjList[n];
    storeGraph(adjList, n, m);
    if (isCyclic(n, adjList))
        cout << "Cyclic" << endl;
    else
        cout << "Not cyclic" << endl;
    return 0;
}